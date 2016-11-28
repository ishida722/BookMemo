#include <vector>
#include <iostream>

using namespace std;

void VectorSurvey()
{
    vector<int> surveyData;
    surveyData.reserve(30);
    int surveyResponse;

    cout << "Enter next survey respone or -1 to end; ";
    cin >> surveyResponse;
    while(surveyResponse != -1){
        surveyData.push_back(surveyResponse);
        cout << "Enter next survey respone or -1 to end; ";
        cin >> surveyResponse;
    }

    int vectorSize = surveyData.size();
    const int MAX_RESPONSE = 10;
    int histgram[MAX_RESPONSE];

    // init
    for(int i=0;i<MAX_RESPONSE;i++){
        histgram[i] = 0;
    }

    // count
    for(int i=0;i<vectorSize;i++){
        histgram[surveyData[i] - 1]++;
    }

    // max
    int mostFrequent = 0;
    for(int i=1;i<MAX_RESPONSE;i++){
        if(histgram[i] > histgram[mostFrequent]) mostFrequent = i;
    }

    mostFrequent++;

    cout << "most frequent is " << histgram[mostFrequent] << " count " <<mostFrequent;
}

int main()
{
    VectorSurvey();
}
