#include<string>
#include<iostream>

using namespace std;

string* addEntry(string *dynamicArray, size_t &size, string newEntry){

    ++size ;
    string * NewArray = new string[size];
    for(size_t j = 0; j <size-1 ; ++j) NewArray[j] = dynamicArray[j];
    NewArray[size-1] = newEntry;
    delete[] dynamicArray;
    return NewArray;
};

string* deleteEntry(string *dynamicArray, size_t &size, string entryToDelete){

    string * NewArray;
    size_t i = 0;

    while( i < size && dynamicArray[i] != entryToDelete)
        ++i ;


    if(i == size){
        NewArray = new string[size];
        for(size_t j = 0; j <size; ++j)
            NewArray[j] = dynamicArray[j];
    }
    else{
        --size;

        NewArray = new string[size];
        for(size_t index = 0 ; index<i ;++index) NewArray[index]=dynamicArray[index];

        for(size_t index = 0;index<size;++index)NewArray[index] = dynamicArray[index+1];
    };


    delete[] dynamicArray;
    return NewArray;

};

void displaysarray(string* strings, size_t size){

    cout<<"{ ";
    for(size_t j =0; j < size - 1;++j) cout<<*(j+strings)<<", ";
    cout<<*(strings+size-1)<<" }";

};


int main(){

    size_t size = 5;
    string* strings = new string[size]
    {"ALaa", "Cole", "Lucii", "Lucca", "Lili"};

    cout<<"the array before add or delete " << endl ;;
    displaysarray(strings, size);
    cout<<endl;;

    strings = deleteEntry(strings, size, "ALaa");

    cout << "the array after delete (alaa) " << endl;
    displaysarray(strings, size);
    cout<<endl ;
    cout << "the array after delete (Cole) " << endl;

    strings = deleteEntry(strings , size , "Cole") ;
    displaysarray(strings , size ) ;
    cout << endl ;
    strings = addEntry(strings, size, "Alaa");
    cout <<"the array after add (alaa) " << endl ;
    displaysarray(strings, size);
    cout<<endl ;
    strings = addEntry(strings, size, "Cole");
    cout <<"the array after add (Cole) " << endl ;
    displaysarray(strings, size);
    cout<< endl ;

    return 0;
};
