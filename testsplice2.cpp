char *splice2(const char *pstr, int pos, int longueur)
{
 int dimension = 0; // longueur de la chaîne

 while (pstr[dimension] != 0)
  dimension++;

 if ((pos < 0) || (longueur <= 0) || (pos >= dimension))
  return 0;

 int max = dimension - longueur;
 if ((pos + longueur) > dimension)
  max = pos;

 int i = 0;
 int j = 0;
 char *pnew_str = new char[max + 1];
 for (; i < max; i++)
 {
  if (i == pos)
   j += longueur;
  pnew_str[i] = pstr[j++];
 }
 pnew_str[i] = 0;
 return pnew_str;
}