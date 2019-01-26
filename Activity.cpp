#include<iostream>
using namespace std;
struct job{
    string jobName;
    int StartTime;
    int EndTime;
};
job *arr;
int noOfJob;

void inputSection()
{
    cout << "input the no of job: " << endl;
    cin >> noOfJob;
    arr = new job[noOfJob];
    cout << "enter jobName,StartTime & EndTime: " << endl;
    for(int i=0; i<noOfJob; i++)
    {

        cin >> arr[i].jobName >> arr[i].StartTime >> arr[i].EndTime;

    }
}
void outputSection()
{

    cout << "JobName    StartTime   EndTime" << endl;
    for(int i =0;i<noOfJob; i++)
    {
        cout <<"  " << arr[i].jobName << "          " <<arr[i].StartTime << "          " << arr[i].EndTime << endl;
    }
}
void sortArray()
{
    int n = noOfJob;
	job temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j].EndTime>arr[j+1].EndTime)
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;

			}

		}

	}


}
void selectedActivity()
{
    cout << "These R the selected activity: " ;
    cout << arr[0].jobName ;
    int count = arr[0].EndTime;
    if(noOfJob>1)
    {
       for(int i =0; i<noOfJob; i++)
        {
            if(count <= arr[i+1].StartTime)
            {
                cout << "     " << arr[i+1].jobName;
                count=arr[i+1].EndTime;
            }
        }
    }
    else return;

}
int main(void)
{
    inputSection();
    sortArray();
    outputSection();
    selectedActivity();
}
