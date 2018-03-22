/*Number Sorter
 * This program will sort and array of 20 integers ascending or decending. 
 * Date: 19/04/11
 * Version: 1.0
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "conio.h"

using namespace std;

//this function prints the array. It was utilized while testing and prints the result.
//inputs: Array, number of items in the aray.
//outputs: Prints the values int he array to the screen.
void printarr(int arr[20],int num){
	int i;
  for(i=0;i<num;++i){
	   cout << arr[i] << " ";}
  cout << endl;}

//this function contains the quicksort algorithm. 
//inputs: array, right position marker, left position marker, order of sorting;
//outputs: array via pointers.
void quicksort(int arr[20],int orlnum, int orrnum,int order){
	int temp,piv,lnum,rnum;
//sets the new left and right numbers as the ones that have been entered into the function
lnum=orlnum;
rnum=orrnum;
//calculates the pivot value. this will always be inbetween the original left and right values entered into the function.
piv=arr[(orrnum+orlnum)/2];

if (order==0){
//while the left number is smaller than or equal to the right number, it will keep on doing the swap.
while(lnum<=rnum){
	//if the left number is bigger than the pivot AND if the right number is smaller that the pivot it will do the swap
	if(arr[lnum]>=piv){
		if(arr[rnum]<=piv){
			temp=arr[lnum];
			arr[lnum]=arr[rnum];
			arr[rnum]=temp;
			//after the swap it will inc left and dec right
			lnum++;
			rnum--;}
		//if the right number is bigger than the pivot, it will dec rnum without doing a swap.
		else{rnum--;}}
	//if the left number is smaller that the pivot it will inc lnum without doing a swap.
	else{lnum++;}}}

if (order==1){
//while the left number is smaller than or equal to the right number, it will keep on doing the swap.
while(lnum<=rnum){
	//if the left number is smaller than the pivot AND if the right number is bigger that the pivot it will do the swap
	if(arr[lnum]<=piv){
		if(arr[rnum]>=piv){
			temp=arr[lnum];
			arr[lnum]=arr[rnum];
			arr[rnum]=temp;
			//after the swap it will inc left and dec right
			lnum++;
			rnum--;}
		//if the right number is smaller than the pivot, it will dec rnum without doing a swap.
		else{rnum--;}}
	//if the left number is bigger that the pivot it will inc lnum without doing a swap.
	else{lnum++;}}}

// the function will call on itself if the orginal left number is smaller than the right number. this does not happen when it has gone all the way down to the left.
if(orlnum<rnum){
	quicksort(arr,orlnum,rnum,order);}
//then it will call on itself if the orginal right number is bigger than the left number. this way the only time it stops is once it has cycled through all the way to the right.
if(orrnum>lnum){
	quicksort(arr,lnum,orrnum,order);}
}
int main(void) {
//initialise variables
   int arr[20], x, i, num, order=0;
   string s="";
   //gets the order for whether it should be sorted ascending or descending.
   cout<<"Please enter 0 if you would like the order to be ascending and 1 if you would like it to be descending"<< endl;
   cin.clear();
   getline(cin,s);
   stringstream ss(s);
   ss>>order;
   // inputs 20 integers
   cout << "Please enter 20 integers which you would like to be sorted and quit by entering a letter.\n"<< endl;
   for(i=0; i<20 && cin >> x; ++i){
	   arr[i] = x;}
//takes one off the number entered to be used for arrays. 
num = i;
num=num-1;
//calls on the quicksort function.
quicksort(arr,0,num,order);

   cout << "here are the numbers:\n" << endl;
   num=num+1;
//calls on the print array function to display the numbers
 printarr(arr,num);
 cout << "Please press any key to close.\n" << endl;
_getch();
	return 0;} 