#include<bits/stdc++.h>
using namespace std;

int hole_numbers, request_numbers,x, y, flag, cnt, fragmentation, min_index, max_index;
vector<int> memory_holes, memory_requests, temp_holes;
vector< pair<int, int> > temp;

void FirstFit(vector<vector<int>> firstFit)
{
    cout<<"\nFirst Fit: \n\n";
    cnt = 0;

    for(int i=0; i<request_numbers; i++)
    {
        flag = 0;
        for(int j=0; j<hole_numbers; j++)
        {
            if(temp_holes[j]>=memory_requests[i])
            {
                cnt++;
                flag = 1;
                temp_holes[j]-=memory_requests[i];

                for(int k=i; k<request_numbers; k++)
                {
                    firstFit[j][k]-=memory_requests[i];
                }

                break;
            }
        }

        if(!flag)
        {
            break;
        }
    }

    if(cnt==request_numbers)
    {
        for(int i=0; i<request_numbers; i++)
        {
            cout<<memory_requests[i]<<"\t";
        }

        cout<<endl<<endl;

        for(int i=0; i<hole_numbers; i++)
        {
            for(int j=0; j<request_numbers; j++)
            {
                cout<<firstFit[i][j]<<"\t";
            }
            cout<<endl;
        }

        cout<<endl<<"No external fragmentation."<<endl;
    }
    else
    {
        fragmentation = 0;

        for(int i=0; i<cnt; i++)
        {
            cout<<memory_requests[i]<<"\t";
        }

        cout<<endl<<endl;

        for(int i=0; i<hole_numbers; i++)
        {
            for(int j=0; j<cnt; j++)
            {
                cout<<firstFit[i][j]<<"\t";
            }
            cout<<endl;
            fragmentation+=firstFit[i][cnt-1];
        }
        cout<<endl<<"Can't be allocated. External fragmentation: "<<fragmentation<<endl;
    }

}

void BestFit(vector<vector<int>> bestFit)
{
    cout<<"\nBest Fit: \n\n";
    cnt = 0;

    for(int i=0; i<request_numbers; i++)
    {
        flag = 0;
        for(int j=0; j<hole_numbers; j++)
        {
            if(temp_holes[j]>=memory_requests[i])
            {
                flag = 1;
                temp.push_back(make_pair(temp_holes[j], j));
            }
        }

        if(!flag)
        {
            break;
        }
        else
        {
            sort(temp.begin(), temp.end());
            min_index = temp[0].second;
            temp_holes[min_index]-=memory_requests[i];

            for(int k=i; k<request_numbers; k++)
            {
                bestFit[min_index][k]-=memory_requests[i];
            }

            cnt++;
            temp.clear();
        }
    }

    if(cnt==request_numbers)
    {
        for(int i=0; i<request_numbers; i++)
        {
            cout<<memory_requests[i]<<"\t";
        }

        cout<<endl<<endl;

        for(int i=0; i<hole_numbers; i++)
        {
            for(int j=0; j<request_numbers; j++)
            {
                cout<<bestFit[i][j]<<"\t";
            }
            cout<<endl;
        }

        cout<<endl<<"No external fragmentation."<<endl;
    }
    else
    {
        fragmentation = 0;

        for(int i=0; i<cnt; i++)
        {
            cout<<memory_requests[i]<<"\t";
        }

        cout<<endl<<endl;

        for(int i=0; i<hole_numbers; i++)
        {
            for(int j=0; j<cnt; j++)
            {
                cout<<bestFit[i][j]<<"\t";
            }
            cout<<endl;
            fragmentation+=bestFit[i][cnt-1];
        }
        cout<<endl<<"Can't be allocated. External fragmentation: "<<fragmentation<<endl;
    }

}

void WorstFit(vector<vector<int>> worstFit)
{

    cout<<"\nWorst Fit: \n\n";
    cnt = 0;

    for(int i=0; i<request_numbers; i++)
    {
        flag = 0;
        for(int j=0; j<hole_numbers; j++)
        {
            if(temp_holes[j]>=memory_requests[i])
            {
                flag = 1;
                temp.push_back(make_pair(temp_holes[j], j));
            }
        }

        if(!flag)
        {
            break;
        }
        else
        {
            sort(temp.rbegin(), temp.rend());
            max_index = temp[0].second;
            temp_holes[max_index]-=memory_requests[i];

            for(int k=i; k<request_numbers; k++)
            {
                worstFit[max_index][k]-=memory_requests[i];
            }

            cnt++;
            temp.clear();
        }
    }

    if(cnt==request_numbers)
    {
        for(int i=0; i<request_numbers; i++)
        {
            cout<<memory_requests[i]<<"\t";
        }

        cout<<endl<<endl;

        for(int i=0; i<hole_numbers; i++)
        {
            for(int j=0; j<request_numbers; j++)
            {
                cout<<worstFit[i][j]<<"\t";
            }
            cout<<endl;
        }

        cout<<endl<<"No external fragmentation."<<endl;
    }
    else
    {
        fragmentation = 0;

        for(int i=0; i<cnt; i++)
        {
            cout<<memory_requests[i]<<"\t";
        }

        cout<<endl<<endl;

        for(int i=0; i<hole_numbers; i++)
        {
            for(int j=0; j<cnt; j++)
            {
                cout<<worstFit[i][j]<<"\t";
            }
            cout<<endl;
            fragmentation+=worstFit[i][cnt-1];
        }
        cout<<endl<<"Can't be allocated. External fragmentation: "<<fragmentation<<endl;
    }

}

int main()
{
    cout<<"Enter number of memory holes: ";
    cin>>hole_numbers;
    cout<<"\nEnter number of memory requests: ";
    cin>>request_numbers;

    vector<vector<int>> firstFit(hole_numbers, vector<int> (request_numbers)),
           bestFit(hole_numbers, vector<int> (request_numbers)),
           worstFit(hole_numbers, vector<int> (request_numbers));

    cout<<"\nMemory holes: ";
    for(int i=0; i<hole_numbers; i++)
    {
        cin>>x;
        for(int j=0; j<request_numbers; j++)
        {
            firstFit[i][j]=x;
            bestFit[i][j]=x;
            worstFit[i][j]=x;
        }
        memory_holes.push_back(x);
        temp_holes.push_back(x);
    }

    cout<<"\nMemory requests: ";
    for(int i=0; i<request_numbers; i++)
    {
        cin>>y;
        memory_requests.push_back(y);
    }

    FirstFit(firstFit);

    temp_holes = memory_holes;
    BestFit(bestFit);

    temp_holes = memory_holes;
    WorstFit(worstFit);
}
