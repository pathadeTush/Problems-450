#include <bits/stdc++.h>
using namespace std;
void nextSmallerElement(int arr[], int nextSmaller[], int n)
{
  if (n == 0)
    return;

  stack<int> st;

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() and st.top() >= arr[i])
      st.pop();

    if (st.empty())
      nextSmaller[i] = -1;
    else
      nextSmaller[i] = st.top();

    st.push(arr[i]);
  }

  return;
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int nextSmaller[n];

  nextSmallerElement(arr, nextSmaller, n);

  for (int i = 0; i < n; i++)
    cout << nextSmaller[i] << " ";

  cout << endl;

  return 0;
}