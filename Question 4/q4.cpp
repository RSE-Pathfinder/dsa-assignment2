#include <fstream>  //ifstream
#include <iostream> //cout
#include <vector>   //vector
#include <queue>    //queue

void printList();   //Prints adjacency list
void reset();       //Macro function to clear working vectors
void DFS(int);      //Depth First Search master function
void DFS2(int);     //Depth First Search recursive function
void BFS(int);      //Breadth First Search master function
void BFS2(int);     //Breadth First Search recursive function

std::vector<std::vector<int>> edgeList;
std::vector<bool> marked;
std::vector<int> edgeTo;
std::vector<int> distTo;

int main(int argc, char** argv){
    std::ifstream fs;
    int v1, v2;
    //Open Graph file
    fs.open(argv[1]);
    //Check if File exists
    if(!fs.is_open()){
        std::cout   << "Error Loading " << argv[1] <<"!\n"
                    << "Please check filename\n";
        exit(1);
    }
    //Find number of vertices
    while(fs >> v1) v2 = v1 > v2 ? v1 : v2;
    //Reserve space for vertices
    edgeList.resize(v2+1);
    fs.clear();
    fs.seekg(0);

    //Load Graph data
    while(fs >> v1 >> v2){
        edgeList[v1].push_back(v2);
        edgeList[v2].push_back(v1);
    }
    //Print Adjacency List
    printList();
    //Apply DFS starting from vertex 0
    DFS(0);
    //Apply BFS starting from vertex 0
    BFS(0);
    fs.close();
}//end main

/**
 * @brief Prints the adjacency list
 * @param none
 * @retval none
 */
void printList(){
    std::cout << "Adjacency List:\n";
    int n{};
    for(std::vector<int> x : edgeList){
        for(int i : x) std::cout << n << "-" << i << "\n";
        n++;
    }
    std::cout << "......\n\n";
}

/**
 * @brief Macro function to clear working vectors
 * @param none
 * @retval none
 */
void reset(){
    marked.resize(edgeList.size());
    edgeTo.resize(edgeList.size());
    distTo.resize(edgeList.size());
    for(size_t i{}; i < edgeTo.size(); i++){
        marked[i] = false;
        edgeTo[i] = -1;
        distTo[i] = -1;
    }
}

/**
 * @brief Depth First Search master function
 * @param v Starting vertex
 * @retval none
 */
void DFS(int v){
    reset();
    std::cout << "DFS vertex sequence:\n" << v;
    DFS2(v);
    std::cout << "\n\n";
}

/**
 * @brief Depth First Search recursive function
 * @param v Vertex
 * @retval none
 */
void DFS2(int v){
    marked[v] = true;
    for(int i : edgeList[v]){
        if(marked[i] == false){
            std::cout << "," << i;
            DFS2(i);
            edgeTo[i] = v;
        }
    }
}

/**
 * @brief Breadth First Search master function
 * @param v Starting vertex
 * @retval none
 */
void BFS(int v){
    reset();
    std::cout << "BFS vertex sequence:\n";
    BFS2(v);
    std::cout << "\n\n";
}

/**
 * @brief Breadth First Search recursive function
 * @param v Vertex
 * @retval none
 */
void BFS2(int v){
    std::queue<int> queue;
    int w;
    queue.push(v);
    marked[v] = true;
    distTo[v] = 0;
    while(queue.size() != 0){
        w = queue.front();
        queue.pop();
        for(int x : edgeList[w]){
            if(marked[x] == false){
                queue.push(x);
                marked[x] = true;
                edgeTo[x] = w;
                distTo[x] = distTo[w] + 1;
            }
        }
        std::cout << w << ((queue.size() == 0) ? "" : ",");
    }
}