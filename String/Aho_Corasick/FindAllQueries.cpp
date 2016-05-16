
#include <iostream>
#include "ACTree.hpp"
#include "ACNode.hpp"
#include <vector>
#include <utility>
#include <fstream>
#include <chrono>
using namespace std;

class Timer{
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  
public:
  
  /*
   * Function called when starting the timer.
   */
  void begin_timer(){
    
    start = std::chrono::high_resolution_clock::now();
    
  }
  
  
  /*
   * Function called when ending the timer. Returns duration in nanoseconds
   * PRECONDITION: begin_timer() must be called before this function
   */
  long long end_timer(){
    
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    end = std::chrono::high_resolution_clock::now();
    
    return (long long)std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    
  }
};


void testTree(std::string dict_filename, std::string data_filename){
  ifstream dict, data(data_filename);
  string dict_word = "", line = "";
  ACTree tree;
  vector<pair<ACNode*, int>> v;
  vector<string> words;
  dict.open(dict_filename);
  
  while(getline(dict, dict_word)){
    if(dict.eof()) break;
    if(!dict_word.empty() && dict_word[dict_word.length()-1] == '\r')
      dict_word.pop_back();
    tree.insert(dict_word);
    words.push_back(dict_word);
  }
  
  string database((istreambuf_iterator<char>(data)),
                  (istreambuf_iterator<char>()));
  if(!database.empty() && database[database.length()-1] == '\r')
    database.pop_back();
  
  tree.updateSuff();
  tree.updateDict_Suff();
  Timer T;
  long long time_duration;
  T.begin_timer();
  v = tree.find(database);
  time_duration = T.end_timer();
  for(string word: words){
    cout << word << ": ";
    int counter = 0;
    for(pair<ACNode*, int> node: v){
      if(node.first->str == word){
        cout << node.second + 1 -node.first->str.length()<<" ";
        counter++;
      }
    }
    if(counter == 0){
      cout<<-1;
    }
    cout << endl;
  }
  cout<<"Running time for finding all queries: "<<time_duration;
  cout<<" nanoseconds"<<endl;
  
  
}
int main(int argc, char *argv[]) {
  if(argc < 3){
    std::cout << "Incorrect number of arguments." << std::endl;
    std::cout << "\t First argument: name of dictionary file." << std::endl;
    std::cout << "\t Second argument: name of database file." << std::endl;
    std::cout << std::endl;
    exit(-1);
  }
  testTree(argv[1],argv[2]);
}