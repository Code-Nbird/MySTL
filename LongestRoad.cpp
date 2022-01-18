#include <iostream>
#include <vector>
using namespace std;

const int MaxNum = 20;

class Graph
{
private:
    int vexnum;
    string vex[MaxNum];
    vector<vector<int> >Edge;
    int Sta;
public:
    void init()
    {
        cin >> this->vexnum;
        for (int i = 0; i < vexnum; i++)
            cin >> vex[i];
        for (int i =0 ; i< vexnum; i++)
        {
            vector<int> row;
            for (int j = 0, a; j < vexnum;j ++)
            {
                cin >> a;
                row.push_back(a);
            }
            Edge.push_back(row);
        }
        string s;
        cin >> s;
        Sta = getpos(s);        
    }
    int getpos(string s)
    {
        for (int i = 0; i < vexnum; i++)
            if (s == vex[i])
                return i;
        return -1;
    }
    void topsort()
    {
        vector<int> Indegree(vexnum, 0);
        vector<bool> vis(vexnum, false);
        vector<int> dist(vexnum,0);
        for (int i = 0; i < vexnum; i++)
        {
            for (int j = 0; j < vexnum; j++)
            {
                if (Edge[j][i])
                    Indegree[i] ++;
            }
        }
        vis[Sta]= true;
        for (int i = 0; i < vexnum;i ++)
        {
            if (Edge[Sta][i] && Indegree[i])
                Indegree[i]--;
        }
        while(1)
        {
            int tar_vex= -1;
            for (int i = 0; i < vexnum; i++)
            {
                if (Indegree[i] == 0 && vis[i])
                    tar_vex = i;
            }
            vis[tar_vex] = true;
            for (int i = 0; i < vexnum; i++)
            {
                if (Edge[tar_vex][i] && )
            }
            for (int i = 0; i  < vexnum; i++)
            {
                if (Edge[tar_vex][i] && Indegree[i])
                    Indegree[i]--;
            }
        }
    }
    void Solution()
    {
        init();
        topsort();

    }

};

int main()
{
    Graph g;
    g.Solution();
    return 0;
}