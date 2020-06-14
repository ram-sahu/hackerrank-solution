#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    
    vector<int> result(queries.size());
    auto n=result.begin();

    for (auto i = queries.begin(); i != queries.end() ; ++i,++n){     
        for (auto j = strings.begin(); j != strings.end(); ++j){
            if( *i==*j ){
                (*n)++;
            }
        }
    }        

return result;
}
