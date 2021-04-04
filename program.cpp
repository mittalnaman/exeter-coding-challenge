#include<bits/stdc++.h>
using namespace std;
int main(){
    fstream fin, fout;
    time_t start,end;
    map<string,string> dict;
    map<string,int> freq;
    time(&start);
    fin.open("find_words.txt",ios::in);
    while (!fin.eof()){
        string line;
        getline(fin, line);
        stringstream s(line);
        string word;
        s>>word;
        freq[word]++;
        if (fin.eof())
            break;
    }
    fin.close();
    fin.open("french_dictionary.csv", ios::in);
    while (!fin.eof()){
        string line;
        getline(fin, line);
        stringstream s(line);
        string word;
        vector<string> row;
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        dict[row[0]]=row[1];
        if (fin.eof())
            break;
    }
    fin.close();
    fout.open("frequency.csv",ios::out);
    for(auto it=freq.begin();it!=freq.end();it++){
        fout<<it->first<<","<<dict[it->first]<<","<<it->second<<"\n";
    }
    fout.close();
    time(&end);
    double time_taken=double(end-start);
    cout<<time_taken<<setprecision(5);
    return 0;
}
