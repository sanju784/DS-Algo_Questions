/*********************************************
*
*  Maximum sum in Sliding Window using array.
*
*/////////////////////////////////////////////

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int arr[] = {3,1,-1,-3,5,3,6,7};
  int w = 3;
  int n = sizeof(arr)/sizeof(int);
  int *res;
  res = (int*)malloc((n-w+1)*sizeof(int));
  for (int i = 0;i < (n - w + 1); i++) {
	  int max = arr[i];
	  for (int j = i + 1; j < (i + w); j++) {
		  if(arr[j] > max)
			  max = arr[j];
	  }
	  res[i] = max;
  }
  cout<<"\nOriginal array is\n";
  for(int i = 0; i < n; i++)
    cout<<arr[i]<<" ";
  cout<<"\n\nThe window size is "<<w<<endl;
  cout<<"\nThe maximum array is\n";
  for(int i = 0; i < (n-w+1); i++)
    cout<<res[i]<<" ";
  return 0;
}
