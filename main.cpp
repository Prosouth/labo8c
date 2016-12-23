#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// -----------------------------------------------------------------------------
// sontEgaux()

bool sontEgaux(const int tab1[], size_t taille1, const int tab2[], size_t taille2)
{
   if (taille1 == 0 && taille2 == 0) {
      return true;
   }
   bool tab1PlusLong;
   size_t tailleTabPlusLong, tailleTabPlusCourt;
   if(taille1 >= taille2)
   {
      tailleTabPlusLong = taille1;
      tailleTabPlusCourt = taille2;
      tab1PlusLong = true;
   }
   else
   {
      tailleTabPlusLong = taille2;
      tailleTabPlusCourt = taille1;
      tab1PlusLong = false;
   }
   for(int i = 0; i < tailleTabPlusLong; i++)
   {
      bool elementEstEgal = false;
      for(int j = 0; j < tailleTabPlusCourt; j ++)
      {
         if(tab1PlusLong && tab1[i] == tab2[j] || !tab1PlusLong && tab2[i] == tab1[j])
         {
            elementEstEgal = true;
            break;
         }
      }
      if(!elementEstEgal)
      {
         return false;
      }
   }
   return true;
}

// -----------------------------------------------------------------------------

string toString(const int tab[], size_t taille)
{
   string output;
   output += "[";
   for (size_t i = 0; i < taille; i++) {
      if (i > 0)
         output += ", ";
      output += to_string(tab[i]);
   }
   output += "]";
   return output;
}

void testSontEgaux(const int tab1[], size_t taille1, const int tab2[], size_t taille2)
{
   cout << toString(tab1, taille1) << " et " << toString(tab2, taille2) << " ";
   if (sontEgaux(tab1, taille1, tab2, taille2)) {
      cout << "sont ";
   } else {
      cout << "ne sont pas ";
   }
   cout << "egaux" << endl;
}

void testToutSontEgaux()
{
   int t0[0];
   int t1[] = {1};
   int t2a[] = {1, 2};
   int t2b[] = {2, 1};
   int t3a[] = {1, 2, 3};
   int t3b[] = {3, 2, 1};
   int t4[] = {1, 2, 3, 4};
   int t5[] = {1, 2, 3, 2, 1};
   testSontEgaux(t0, 0, t0, 0);
   testSontEgaux(t1, 1, t1, 1);
   testSontEgaux(t2a, 2, t2b, 2);
   testSontEgaux(t3a, 3, t3b, 3);
   testSontEgaux(t3a, 3, t4, 4);
   testSontEgaux(t3a, 3, t5, 5);
}

int main()
{
   testToutSontEgaux();
   return EXIT_SUCCESS;
}