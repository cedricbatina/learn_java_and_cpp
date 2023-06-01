// lecture d'un repertoire en c++

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 DIR *pdir;
 struct dirent *pdirent;
 struct stat statbuf;
 if ((pdir = opendir(".")) == NULL)
 {
  cout << "Ne peut ouvrir le répertoire. " << endl;
  return -1;
 }
 while ((pdirent = readdir(pdir)) != NULL)
 {
  cout << "Fichier: " << pdirent->d_name << endl;
  if (stat(pdirent->d_name, &statbuf) != 0)
   continue;
  if (statbuf.st_mode & S_IWRITE)
  {
   cout << "Nous avons la permission d'écrire" << endl;
  }
  else
  {
   cout << "Nous n'avons pas la permission d'écrire!" << endl;
  }
 }
 if (statbuf.st_mode & S_IWRITE)
 {
  cout << "C'est un réperoire" << endl;
 }
 cout << "La lettre du disque: " << (char)('A' + statbuf.st_dev) << endl;
 cout << "La dimension en octets: " << statbuf.st_size << endl;
 cout << "La dernière fois qu'il fut ouvert: " << ctime(&statbuf.st_ctime) << endl;
 closedir(pdir);
 return 0;
}
