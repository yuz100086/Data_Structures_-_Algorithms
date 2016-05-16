#include "ACTree.hpp"

using namespace std;
void ACTree::deleteAll(ACNode* node){
  if (node == 0)
  {
    return;
  }
  
  for (auto n: *(node->children))
  {
    deleteAll(n);
  }
  
  delete node;
}

ACTree::~ACTree() {
  deleteAll(root);
}

bool ACTree::insert(string word) {
  int num = 0;
  if (word.length() == 0)
  {
    return 0;
  }
  
  if(!word.empty() && word[word.length()-1] == '\n')
    word.erase(word.length()-1);

  ACNode* temp = root;
  
  for (unsigned long i = 0; i < word.length(); ++i)
  {
    if (word[i] == ' ')
    {
      num = 0;
    }else{
      num = word[i] - 'A' + 1;
    }
    if ((*(temp->children))[num] == 0)
    {
      if (i == (word.length() - 1))
      {
        (*(temp->children))[num] = new ACNode(word[i], true, word);
      }else{
        (*(temp->children))[num] = new ACNode(word[i], false);
      }
      
    }else{
      if (i == (word.length() - 1))
      {
        if((*(temp->children))[num]->is_word)
          return 0;
        (*(temp->children))[num]->is_word = true;
        (*(temp->children))[num]->str = word;
        return 1;
      }
    }
    temp = (*(temp->children))[num];
  }
  return 1;
  
}



vector<pair<ACNode*, int>> ACTree::find(string word) {
  ACNode* temp = root;
  vector<pair<ACNode*, int>> toReturn;
  if(!word.empty() && word[word.length()-1] == '\n')
    word.erase(word.length()-1);
  for (unsigned long i = 0; i < word.length(); ++i)
  {
    int num = (word[i]==' ')? 0: word[i] - 'A' + 1;
    
    if((*(temp->children))[num] != 0){
      
      if((*(temp->children))[num]->is_word){
        pair<ACNode*, int> tempPair((*(temp->children))[num], i);
        toReturn.push_back(tempPair);
      }
      if((*(temp->children))[num]->dict_suff!=0){
        pair<ACNode*, int> tempPair((*(temp->children))[num]->dict_suff, i);
        toReturn.push_back(tempPair);
      }
      
      temp = (*(temp->children))[num];
      continue;
    }
    
    while ((*(temp->children))[num] == 0){
      temp = temp->suff;
      if (temp == 0)
      {
        temp = root;
        break;
      }
      
      if ((*(temp->children))[num] != 0)
      {
        if ((*(temp->children))[num]->is_word){
          pair<ACNode*, int> tempPair((*(temp->children))[num], i);
          toReturn.push_back(tempPair);
        }
        if((*(temp->children))[num]->dict_suff!=0){
          pair<ACNode*, int> tempPair((*(temp->children))[num]->dict_suff, i);
          toReturn.push_back(tempPair);
        }
        temp = (*(temp->children))[num];
        break;
      }
    }
  }
  return toReturn;
}

void ACTree::updateNode(ACNode* node, string str){
  if (node == 0)
  {
    return;
  }
  
  for (auto n: *(node->children))
  {
    if(n != 0)
      updateNode(n, str + (char)n->symbol);
  }
  
  for (unsigned long i = 1; i < (str.length()+1); ++i)
  {
    string toFind = str.substr(i, str.length());
    
    ACNode* temp = root;
    
    if (toFind.length() == 0)
    {
      node->suff = temp;
      return;
    }
    
    for(unsigned long j = 0; j < toFind.length(); j++){
      int num = (toFind[j]==' ') ? 0: (toFind[j] - 'A' + 1);
      if ((*(temp->children))[num] != 0)
      {
        temp = (*(temp->children))[num];
      }else{
        break;
      }
      
      if (j == (toFind.length()-1))
      {
        node->suff = temp;
        return;
      }
    }
    
  }
  
  
}
void ACTree::updateSuff(){
  updateNode(root, "");
}

void ACTree::updateDict_Suff(){
  updateDict(root);
}

void ACTree::updateDict(ACNode* node){
  if (node == 0)
  {
    return;
  }
  
  for (auto n: *(node->children))
  {
    if(n != 0)
      updateDict(n);
  }
  
  ACNode* temp = node->suff;
  
  while(temp != 0 && !temp->is_word) {
    temp = temp->suff;
  }
  
  node->dict_suff = temp;
  
}