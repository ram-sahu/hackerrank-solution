#include <bits/stdc++.h>

using namespace std;
                                                        //inorder traversal
void inorder(int inode, vector<pair<int,int>> tree, vector<int> &traversal){
    auto node= 
        find_if(tree.begin(), tree.end(), [inode] (pair<int,int> p)->bool
        {
                if(p.first==inode) return true;
                else return false;
        } );

    if(node!=tree.end()){
        inorder( 2*(node->first), tree, traversal);
        traversal.push_back(node->second);
        inorder( 2*(node->first)+1, tree, traversal);
    }

}

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
     vector<vector<int> > result( queries.size() , vector<int> ());
     auto res=0;

     for(int &k: queries){                  //for every query
         vector<pair<int,int>> tree;
         int h=1,traverse=1,indx=0,itree=0;
         int total_count=0,count=0,run=1;
         tree.push_back(make_pair(1,1));

         while(run){                                 // for travese indexes
            traverse= int(pow(2,h-1))-total_count; //for counting H

            count=0;
            for(; traverse>0 &&run &&indx<indexes.size(); --traverse,++indx){
                if(indexes.size()-1 == indx) run=0;

                if(indexes[indx][0]== -1) ++count;       //for count(-1)
                if(indexes[indx][1]== -1) ++count;

                if(h%k==0){                                //for swap nodes
                    swap(indexes[indx][0],indexes[indx][1]);
                }
                
                int c=0;                     //for making pair<index,data> tree
                for(auto &i:indexes[indx]){
                    if(i!= -1){
                       tree.push_back(make_pair( (2*(tree[itree].first))+c, i));
                    }
                    ++c; 
                }
                ++itree;

                cout<<indexes[indx][0]<<"+"<<indexes[indx][1]<<"\t"; 
                                          //print given formate tree
            }

            total_count= 2*total_count+count; //counting number of null i.e(-1) node
            ++h;
            cout<<"\n";
        }

        cout<<"\ntree\n";      //print pair<index,data> tree
        for(auto &i:tree){
            cout<<i.first<<"-"<<i.second<<"\n";
        }
        cout<<"\n\n";

        //traverse in inorder the tree

        inorder(1,tree,result[res]);
        ++res;
     }


    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
