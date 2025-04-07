/*
std::map is a sorted associative container that contains key-value pairs with unique keys
*/
#include<iostream>
#include<map>
int main(){
std::map<int,char>mp;
mp.insert({1,'a'});
mp[2] = 'b';
mp.insert({3,'c'});

// element access through at() or [] both , but at is desirable

//std::cout<<mp[4]<<std::endl; // if key is not present it will create an entry for it so try to not use it 
//std::cout<<mp.at(4)<<std::endl; // throw out_of_range exception since key is not present

std::cout<<mp.at(2)<<std::endl;

for(std::map<int,char>::iterator it = mp.begin();it!=mp.end();it++){
    std::cout<<(*it).first<<"--> "<<(*it).second<<std::endl;;
}
mp.emplace(4,'d');//constructs element in-place


std::cout<<"Before Erase :"<<std::endl;
for(std::map<int,char>::iterator it = mp.begin();it!=mp.end();it++){
    std::cout<<(*it).first<<"--> "<<(*it).second<<std::endl;;
}


/* try_emplace(introduced in cpp17 here it not work)
//inserts in-place if the key does not exist, does nothing if the key exists
mp.try_emplace(4,'l'); // already key exist it will do nothing
mp.try_emplace(5,'e');//create entry bcoz key already not present

for(auto i:mp){
    std::cout<<i.first<<"--> "<<i.second<<std::endl;
}
*/

//erase same as vector erase it take iterator as argument
for(std::map<int,char>::iterator it = mp.begin();it!=mp.end();){
    if(it->first%2!=0)
    it = mp.erase(it);
    else
    it++;
}
std::cout<<"After Erase :"<<std::endl;
for(std::map<int,char>::iterator it = mp.begin();it!=mp.end();it++){
    std::cout<<it->first<<"--> "<<it->second<<std::endl;;
}


//count ()  return 1 if key is present,else return 0
// find()  return itertor to key, if not present return end()
// contains () return true if key is present else return false (cpp20)
// if(mp.contains[key]){
//   std::cout<<mp[key]<<std::endl;
//  }


// equal_range() is leftout
return 0;
}