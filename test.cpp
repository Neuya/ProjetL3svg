#include <cairo.h>
#include <gtk/gtk.h>
#include <librsvg/rsvg.h>
#include <gio/gfile.h>
#include <tinyxml2.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <list>
#include <gtk/gtk.h>
#include <fstream>
#include <map>
#include <stdio.h>
#include <unistd.h>
#include <thread>
#include "traitement.hpp"
#include "data.hpp"


using namespace tinyxml2;
using namespace std;

static void do_drawing(cairo_t *);
static void do_drawing_svg(cairo_t *);


RsvgHandle *svg_handle;
int x = 10;
int y = 0;

gpointer user_data;
GtkWidget *darea;

Traitement t;
Data dataCourante;


map<string,string> mapModifs;


static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
  user_data = user_data;

  do_drawing_svg(cr);

  return FALSE;
}

void afficheMap(map<string,string> m)
{
  for(map<string,string>::iterator it=m.begin();it!=m.end();it++)
  {
    cout << it->first << "[]" << it->second << endl;
  }
}

static void do_drawing_svg(cairo_t * cr)
{

  XMLPrinter printer;
  XMLDocument svg_data;
  svg_data.LoadFile("toto.svg");
  XMLElement* xmlElement = svg_data.RootElement();

  const char* target_x = "cx";
  const char* target_y = "cy";
  string line;

  map<string,string>::iterator it;
  
  map<string,string> mapModifs = dataCourante.mapCourante;


  int val1 = 0;
  int val2 = 0;
  bool mapDone = true;
  for(it=mapModifs.begin();it!=mapModifs.end();it++)
  {
    for (size_t i=0; i<14; i++)
    {
      string s(xmlElement[i].Value());
        if (s == "driven" &&  (xmlElement[i].FirstAttribute()->Next()->Value() == it->first ))
        {
          string current_pos;
          const char* new_pos= it->second.c_str();

          val2 = atoi(new_pos);

            const char* attribute = xmlElement[i].FirstAttribute()->Value();
            //cout<<"attribute "<<attribute<<endl;

            current_pos = xmlElement[i].Parent()->ToElement()->Attribute(attribute);

            val1 = stoi(current_pos);
            //cout << " current_ posq : " << current_pos << " x new_pos : " << new_pos << endl;
            if (! (val1 == val2))
            {
              mapDone = false;
              val1 > val2? val1--:val1++;
                  xmlElement[i].Parent()->ToElement()->SetAttribute(attribute,val1);
            }

          svg_data.SaveFile("toto.svg",false);

      }

      svg_data.Print(&printer);

      svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize()-1, NULL);

      rsvg_handle_render_cairo(svg_handle, cr);

      gtk_widget_queue_draw(darea);
    }
  }

  if(mapDone)
  {
   //cout << "MapDone" << endl;
      /*cout<< "En attente" << endl;
      string elem;
      bool done = true;
      while(done)
      {
        cout << "Entrez un element a modifier (done pour terminer):  ";
        cin >> elem;
        string coor;
        if (elem == "done")
        {
          done = false;
        }
        else
        {
          cout << "Entrez la coordonée de cet element: ";
          cin >> coor;
          mapModifs[elem]=coor;
        }
      }*/
      dataCourante.nextMap();
      //t.printMapCourante();
  }
}

void task1()
{
   
    while(1)
    {
      t.recvDataAndStockMap(&dataCourante);
    }
}

void task2(int argc,char* argv[])
{
  cout << "Programme Parent" << endl;
      gtk_init(&argc, &argv);
      GtkWidget *window;
      //mapModifs["sun_x"]="20";
      //mapModifs["sun_y"]="80";
      //mapModifs["house_x"]="60";
      //mapModifs["house_y"]="65";
  
      window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      darea = gtk_drawing_area_new();
      gtk_container_add(GTK_CONTAINER(window), darea);
  
      g_signal_connect(darea, "draw",
        G_CALLBACK(on_draw_event), NULL);
  
      g_signal_connect(window, "destroy",
        G_CALLBACK(gtk_main_quit), NULL);
  
  
      gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  
      gtk_window_set_title(GTK_WINDOW(window), "GTK window");
  
      gtk_widget_show_all(window);
  
      gtk_main();
}




int main(int argc, char *argv[])
{

  cout << "Begin" << endl;

 /* pid_t pid = fork();


  if(pid > 0)
  {
    cout << "Programme enfant" << endl;
    int iii = 0;
    while(iii<10)
    {
      t.recvDataAndStockMap(&dataCourante);
      if(iii%3==0)
      {
        t.nextMap();
      }
      iii++;
    }
  }
  else if(pid == 0)
  {
      cout << "Programme Parent" << endl;
      gtk_init(&argc, &argv);
      GtkWidget *window;
      //mapModifs["sun_x"]="20";
      //mapModifs["sun_y"]="80";
      //mapModifs["house_x"]="60";
      //mapModifs["house_y"]="65";
  
      window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
      darea = gtk_drawing_area_new();
      gtk_container_add(GTK_CONTAINER(window), darea);
  
      g_signal_connect(darea, "draw",
        G_CALLBACK(on_draw_event), NULL);
  
      g_signal_connect(window, "destroy",
        G_CALLBACK(gtk_main_quit), NULL);
  
  
      gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  
      gtk_window_set_title(GTK_WINDOW(window), "GTK window");
  
      gtk_widget_show_all(window);
  
      gtk_main();
   }*/

  thread t1(task1);
  thread t2(task2,argc,argv);
  t1.join();
  t2.join();




  /**/
  


  //  rsvg_handle_get_geometry_for_element  (svg_handle, NULL, &viewport, NULL, NULL);

  return 0;
}