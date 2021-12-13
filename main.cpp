/*** VERSICULO ALEATORIO EN ESPAÑOL, REINA VALERA 1960   ***/
/*** LUIS G. NAVARRO, 2021                               ***/
/*** Para la Gloria del Dios Grandísimo, al Únicio Digno ***/
/*** de todo nuestro tiempo, y nuestra vida.             ***/


#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

std::string wrap(const char *text, size_t line_length = 72)
{
    std::istringstream words(text);
    std::ostringstream wrapped;
    std::string word;
 
    if (words >> word) {
        wrapped << word;
        size_t space_left = line_length - word.length();
        while (words >> word) {
            if (space_left < word.length() + 1) {
                wrapped << '\n' << word;
                space_left = line_length - word.length();
            } else {
                wrapped << ' ' << word;
                space_left -= word.length() + 1;
            }
        }
    }
    return wrapped.str();
}

// Código wrap de https://www.rosettacode.org/wiki/Word_wrap#C.2B.2B

int main(){

   // Por manuales de rapidXML, código construido sin tomar de otros lugares
   // Se puede hacer lo que es lectura desde la línea de comandos
   ifstream myfile("/etc/versiculoaleatorio/RVR1960.xmm");
   rapidxml::xml_document<> doc;
   int i,j,k=0;
   int rand_i; int rand_j; int rand_k;
   int max_k[67][151];
   int max_j[67];
   /* "Read file into vector<char>"  See linked thread above*/
   vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));

   buffer.push_back('\0');

   //cout<<&buffer[0]<<endl; /*test the buffer */

   doc.parse<0>(&buffer[0]); 

   //cout << "Name of my first node is: " << doc.first_node()->name() << "\n";  /*test the xml_document */
   rapidxml::xml_node<> *pRoot = doc.first_node();
   //cout << "Prueba de Lectura de Archivo Bíblico \n";
   
   
   // Conteo de Capítulos y Versículos
 
   i=0;
   for(rapidxml::xml_node<> *pBook=pRoot->first_node("b"); pBook; pBook=pBook->next_sibling())
   {
      i++;
      std::string conv_i = std::to_string(i);
      const char * number_i = conv_i.c_str();
      // This loop will walk you through two nodes:
      //rapidxml::xml_attribute<> *pAttr = pBook->first_attribute("n");
      pBook-> append_attribute(doc.allocate_attribute("i", number_i));
      //cout << "Libro número " << pBook->first_attribute("i")->value() << ": " << pBook->first_attribute("n")->value() << "\n";
      //cout << pBook->first_attribute("i")->value() << ", " << pBook->first_attribute("n")->value() << ", ";
      j=0;
      for(rapidxml::xml_node<> *pChap=pBook->first_node("c"); pChap; pChap=pChap->next_sibling())
      {
         j++;
         //cout << "Capítulo " << pChap->first_attribute("n")->value() ; 
         //cout << pChap->first_attribute("n")->value()<<", ";
         k=0;
         for(rapidxml::xml_node<> *pVerse=pChap->first_node("v"); pVerse; pVerse=pVerse->next_sibling())
         {
            k++;
         }
         
         std::string conv_k = std::to_string(k);
         const char * number_k = conv_k.c_str();
         pChap-> append_attribute(doc.allocate_attribute("count", number_k));
         //cout << " con " << pChap->first_attribute("count")->value() <<" versículos \n";
         max_k[i][j]=k;
         //cout << "Versículos, Libro: " << i << " Capítulo: " << j << " :" << max_k[i][j] << "\n";
         //cout << pBook->first_attribute("i")->value() << ", " << pBook->first_attribute("n")->value() << ", ";
         //cout << pChap->first_attribute("n")->value()<<", ";
         //cout << k <<"\n";
      }
      std::string conv_j = std::to_string(j);
      const char * number_j = conv_j.c_str();
      pBook-> append_attribute(doc.allocate_attribute("count", number_j));
      max_j[i]=j;
      //cout << "Total de Capítulos: " << pBook->first_attribute("count")->value() <<"\n";
      //cout << "Capítulos: " << max_j[i] <<"\n";
   }
   

   // Imprimir maximos en CSV: archivo sacado de terminal

   // Cargar máximos de archivo para el sistema.
   
   // TODO: Cargar para variables de máximos.
   // Puede ser innecesario, desde que los máximos se tengan desde el Texto en XML



   // Código de Foros, para usar el /dev/urandom
   unsigned long long int random_value_i = 0; //Declare value to store data into
   size_t size_i = sizeof(random_value_i); //Declare size of data
   ifstream urandom_i("/dev/urandom", ios::in|ios::binary); //Open stream
    if(urandom_i) //Check if stream is open
    {
        urandom_i.read(reinterpret_cast<char*>(&random_value_i), size_i); //Read from urandom
        if(urandom_i) //Check if stream is ok, read succeeded
        {
            //std::cout << "Read random value: " << random_value_i << std::endl;
        }
        else //Read failed
        {
            std::cerr << "Failed to read from /dev/urandom" << std::endl;
        }
        urandom_i.close(); //close stream
    }
    else //Open failed
    {
        std::cerr << "Failed to open /dev/urandom" << std::endl;
    }
   
   unsigned long long int random_value_j = 0; //Declare value to store data into
   size_t size_j = sizeof(random_value_j); //Declare size of data
   ifstream urandom_j("/dev/urandom", ios::in|ios::binary); //Open stream
    if(urandom_j) //Check if stream is open
    {
        urandom_j.read(reinterpret_cast<char*>(&random_value_j), size_j); //Read from urandom
        if(urandom_j) //Check if stream is ok, read succeeded
        {
            //std::cout << "Read random value: " << random_value_j << std::endl;
        }
        else //Read failed
        {
            std::cerr << "Failed to read from /dev/urandom" << std::endl;
        }
        urandom_j.close(); //close stream
    }
    else //Open failed
    {
        std::cerr << "Failed to open /dev/urandom" << std::endl;
    }

   unsigned long long int random_value_k = 0; //Declare value to store data into
   size_t size_k = sizeof(random_value_k); //Declare size of data
   ifstream urandom_k("/dev/urandom", ios::in|ios::binary); //Open stream
   if(urandom_k) //Check if stream is open
    {
        urandom_k.read(reinterpret_cast<char*>(&random_value_k), size_k); //Read from urandom
        if(urandom_k) //Check if stream is ok, read succeeded
        {
            //std::cout << "Read random value: " << random_value_k << std::endl;
        }
        else //Read failed
        {
            std::cerr << "Failed to read from /dev/urandom" << std::endl;
        }
        urandom_k.close(); //close stream
    }
    else //Open failed
    {
        std::cerr << "Failed to open /dev/urandom" << std::endl;
    }
   

   srand(time(NULL));

   
      rand_i=(random_value_i+10000*rand()) % 66; // Máximo 66
      if (rand_i == 0)
         do 
         {
            rand_i=(random_value_i+10000*rand()) % 66;
         }
         while (rand_i == 0);
      //cout << rand_i << "\n";
      rand_j=(random_value_j+10000*rand()) % (max_j[rand_i]); // Máximo 150
      if (rand_j == 0)
         do
         {
            rand_j=(random_value_j+10000*rand()) % (max_j[rand_i]);
         }
         while (rand_j == 0);
      //cout << rand_j << "\n";
      rand_k=(random_value_k+10000*rand()) % (max_k[rand_i][rand_j]); // Máximo 176
      if (rand_k == 0)
         do
         {  
            rand_k=(random_value_k+10000*rand()) % (max_k[rand_i][rand_j]);
         }
         while (rand_k == 0);

      //cout << rand_k << "\n";
      
  

   // Prueba de recuperación
   int retr_i=rand_i;
   int retr_j=rand_j;
   int retr_k=rand_k;
   int flag;
   i=0;
   for(rapidxml::xml_node<> *pBook=pRoot->first_node("b"); pBook; pBook=pBook->next_sibling())
   {
      i++;
      // This loop will walk you through two nodes:
      //rapidxml::xml_attribute<> *pAttr = pBook->first_attribute("n");
      if(retr_i == i)
      {
         cout << pBook->first_attribute("n")->value() << " ";
         j=0;
         for(rapidxml::xml_node<> *pChap=pBook->first_node("c"); pChap; pChap=pChap->next_sibling())
         {
            j++;
            if(retr_j == j)
            {
               cout << "Capítulo " << pChap->first_attribute("n")->value() << " ";
               k=0;
               for(rapidxml::xml_node<> *pVerse=pChap->first_node("v"); pVerse; pVerse=pVerse->next_sibling())
               {
                  k++;
                  if(retr_k == k)
                  {
                     cout << "Versículo " << pVerse->first_attribute("n")->value() << ":\n \n";
                     cout << wrap(pVerse->value(),31) <<"\n"; 
                     flag=1;
                  }
               }
               k=0;
            }   
         }
         j=0;
      }     
   }


    // cout << " con " << j << " capítulos \n";
    // Do something here
   
   
    

}