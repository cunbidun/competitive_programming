#ifndef _GENLIB_H_
#define _GENLIB_H_
#include "testlib.h"
#include <iostream>
using namespace std;

string gen_string(int n, bool lower, bool upper, bool number, string custom, bool p = true)
{
  string s = "";
  if (custom == "")
  {
    if (lower)
    {
      custom += "a-z";
    }
    if (upper)
    {
      custom += "A-Z";
    }
    if (number)
    {
      custom += "0-9";
    }
  }
  s = rnd.next("[" + custom + "]{" + to_string(n) + "}");
  if (p)
  {
    cout << s;
  }
  return s;
}

template <class T>
vector<T> gen_array(int n, T min_val, T max_val, bool p = true)
{
  vector<T> array;
  for (int i = 0; i < n; i++)
  {
    array.push_back(rnd.next(min_val, max_val));
  }
  if (p)
  {
    for (int i = 0; i < n; i++)
    {
      if (i != 0)
      {
        cout << " ";
      }
      cout << rnd.next(min_val, max_val);
    }
  }
  return array;
}

#endif
