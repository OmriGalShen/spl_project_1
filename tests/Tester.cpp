#include "../include/Session.h"
#include "../tests/Tester.h"
#include <csignal>
#include <iostream>
#include <fstream>
using namespace std;

//Coded By Ron Rachev

Tester * testGenerator;

void signalHandler(int signal){
    std::cout << "Unknown Exception! Try running generatedTest.json Manually!" << std::endl;
    exit(signal);
}
int main(int argc, char** argv){

//    Session testSession("../config1.json");
    //  testSession.simulate();


    signal(SIGSEGV,signalHandler);
    srand(time(NULL));
    int testerOptionChosen = 0;

    std::cout << "---------------\r\nWelcome\r\n---------------\r\nPlease type 1 to generate tests or 2 to run tests file" << std::endl;
    cin >> testerOptionChosen ;

    if(testerOptionChosen == 2) {
        testGenerator = new Tester(2, 1);
        testGenerator->initate();
        std::cout << "----------------------\r\nTotal Passed Tests : " << testGenerator->numPassedTests
                  << "\r\nFailed Tests : " << testGenerator->numInvalidTests << "\r\n----------------------\r\n"
                  << std::endl;
        delete (testGenerator);
    }else
    if(testerOptionChosen == 1){
        std::cout << " Generating Random 4000 Tests " << std::endl;
        for(int i = 0 ;i < 4000 ; i ++)
        {
            testGenerator = new Tester(1,i);
            testGenerator->initate();
            delete(testGenerator);
        }
        std::cout << "\r\nTests Written To tests.json, have fun." << std::endl;
    }else
        std::cout << "Invalid Input" << std::endl;
    return 0;
}

//Coded By Ron Rachev
Tester::~Tester(){}

Tester::Tester(const int option,int testId) : option(option) {}

//Used for debugging purposes only.
void Tester::printGraph(const std::vector<std::vector<int>> & input) {
    for(int i = 0; i < input.size(); i ++){
        for(int r = 0; r < input.size() ; i ++){  std::cout << input[i][r];  }
        std::cout << " " <<std::endl;}
}
//Converts Agents To Readable Json Format
void Tester::agentsToJson(json & j , const std::vector<jsonAgent> &input)
{
    for(int i = 0 ; i < input.size(); i++)
        j["agents"].push_back({input[i].type,input[i].idStart});
}
//Returns file contents
std::string Tester::readAndGetFile(const std::string & path){
    std::ifstream resultFile(path);
    std::string parsedData;
    if(resultFile.is_open())
    {
        std::string line;
        while(std::getline(resultFile,line))
            parsedData.append(line);
        resultFile.close();
    }
    return parsedData;
}
void Tester::generateTests() {
    json generatedTest;
    json entireTest   ;

    int numNodesInGraph = ( rand() % 10) +3;
    int numEdges        = ( rand() % 8) +3;
    int numViruses      = ( rand() % 3 ) +1;
    int numContactors   = ( rand() % 2 ) +1;
    int totalAgentListSize = numContactors + numViruses;
    std::vector <std::vector<int>> graphMatrix (numNodesInGraph, std::vector<int>(numNodesInGraph,0));
    for(int i = 0; i < numEdges ; i++)
    {
        int u = ( rand() % (numNodesInGraph-1) ) +1;
        int v = ( rand() % (numNodesInGraph-1) ) +1;
        if(u != v) {
            graphMatrix[u][v] = 1;
            graphMatrix[v][u] = 1;
        }
    }
    std::vector<jsonAgent> agentList (totalAgentListSize,jsonAgent());
    std::vector<bool> usedStartingPoints(numNodesInGraph,false);
    for(int i = 0; i < totalAgentListSize ;i++)
    {
        if(i < numContactors){
            agentList[i].idStart = -1;
            agentList[i].type    = "C";
        }else {
            int randStartingPoint = ( rand () % (numNodesInGraph));
            while(usedStartingPoints[randStartingPoint]){
                randStartingPoint=( rand () % (numNodesInGraph)) ;
            }
            usedStartingPoints[randStartingPoint]=true;
            agentList[i].idStart = randStartingPoint;

            agentList[i].type    = "V";
        }
    }
    agentsToJson(generatedTest,agentList);
    for(int i = 0 ; i < graphMatrix.size(); i++)
        generatedTest["graph"].push_back(graphMatrix[i]);

    std::string treeType;
    int randomTreeType = ( rand () % (3) + 1);
    if(randomTreeType == 1)
        treeType = "M";
    else if(randomTreeType == 2) treeType = "R";
    else treeType = "C";

    generatedTest["tree"] = treeType;

    std::ofstream randomTestWriter("./generatedTest.json");
    randomTestWriter << generatedTest;
    randomTestWriter.close();
    //Run user simulation
    Session     testSession("./generatedTest.json");
    testSession.simulate();
    //Parse results and save to json format ;)
    std::string parsedData = Tester::readAndGetFile("./output.json");
    json testParser = json::parse(parsedData);

    entireTest["graph"]     = graphMatrix;
    entireTest["agents"]    = generatedTest["agents"];
    entireTest["tree"]      = generatedTest["tree"];
    entireTest["resultRunGraph"] = testParser["graph"];
    entireTest["resultRunInfected"] = testParser["infected"];

    std::ofstream testAppender("../tests.json",std::ios_base::app);
    testAppender << entireTest << "\r\n" ;
    testAppender.close();
}
void Tester::runTests() {
    std::ifstream resultFile("../tests.json");
    std::string   parsedData;
    if (resultFile.is_open()) {
        std::string line;
        while (std::getline(resultFile, line)) {
            json jsonTestParser = json::parse(line);

            std::vector<int>              infectedListFromTest = jsonTestParser["resultRunInfected"];
            std::vector<std::vector<int>> graphFromTest        = jsonTestParser["resultRunGraph"];

            std::ofstream testAppender("./run.json");
            testAppender << jsonTestParser;
            testAppender.close();

            Session s("./run.json");
            s.simulate();

            //Handle the output results from the user
            std::string userResult = Tester::readAndGetFile("./output.json");
            json outputParser      = json::parse(userResult);

            std::cout << outputParser << std::endl;
            std::vector<int>              infectedListFromUser = outputParser["infected"];
            std::vector<std::vector<int>> graphFromUser        = outputParser["graph"];

            bool passedGraphTest        = true;
            bool passedInfectedListTest = true;
            for(int i = 0; i < graphFromUser.size() && passedGraphTest; i++){
                for(int j = 0 ; j < graphFromUser[i].size() && passedGraphTest; j++)
                    if(graphFromUser[i][j] != graphFromTest[i][j]) passedGraphTest = false;
            }
            std::sort(infectedListFromUser.begin(),infectedListFromUser.end());
            std::sort(infectedListFromTest.begin(),infectedListFromTest.end());

            if(infectedListFromUser.size() != infectedListFromTest.size())
                passedInfectedListTest = false;
            if(passedInfectedListTest){
                for(int i = 0; i < infectedListFromUser.size() && passedInfectedListTest; i++)
                    if(infectedListFromUser[i] != infectedListFromTest[i]) passedInfectedListTest = false;
            }
            if(passedInfectedListTest && passedGraphTest) {
                std::cout << "Passed Test! " << std::endl;
                numPassedTests ++;
            }else {
                std::cout << "Failed Test ! " << " | Test Input : " << jsonTestParser << " | " << std::endl;
                std::cout << "Your Result -> " << userResult << std::endl;
                numInvalidTests ++;
            }
        }
        resultFile.close();
    }

}
void Tester::initate() {
    switch (option)
    {
        case 1:
            generateTests();
            break;
        case 2:
            runTests();
            break;
    }
}