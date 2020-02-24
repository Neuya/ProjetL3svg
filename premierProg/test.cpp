#include <cairo.h>
#include <gtk/gtk.h>
#include <librsvg/rsvg.h>
#include <gio/gfile.h>
#include <tinyxml2.h>
#include <iostream>
#include <thread>
#include <chrono>


using namespace tinyxml2;
using namespace std;

static void do_drawing(cairo_t *);
static void do_drawing_svg(cairo_t *);


RsvgHandle *svg_handle;
int x = 10;
int y = 0;
gpointer user_data;
// RsvgRectangle viewport;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
  user_data = user_data;
  do_drawing_svg(cr);

  return FALSE;
}

static void do_drawing_svg(cairo_t * cr)
{
  XMLPrinter printer;
  XMLDocument svg_data;
  svg_data.LoadFile("toto.svg");
  XMLElement* xmlElement = svg_data.RootElement();
  for (size_t i = 0; i < 12; i++) {
    string s(xmlElement[i].Value());
    std::cout << xmlElement[i].Value()<< '\n';
    if (s == "circle") {
      std::cout << "test"<< '\n';
      xmlElement[i].SetAttribute("cx",x+=1);
      xmlElement[i].SetAttribute("cy",y+=1);
      svg_data.SaveFile("toto.svg",false);
    }
  }
  svg_data.Print(&printer);
  svg_handle = rsvg_handle_new_from_data ((const unsigned char*) printer.CStr(), printer.CStrSize()-1, NULL);

  rsvg_handle_render_cairo(svg_handle, cr);

}





int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);
  GtkWidget *window;
  GtkWidget *darea;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  darea = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), darea);
  gtk_widget_set_events (darea, GDK_EXPOSURE_MASK
             | GDK_LEAVE_NOTIFY_MASK
             | GDK_KEY_PRESS_MASK
             | GDK_POINTER_MOTION_MASK
             | GDK_POINTER_MOTION_HINT_MASK);

  //fonction permettant d'afficher l'image SVG
   g_signal_connect(darea, "draw",
       G_CALLBACK(on_draw_event), NULL);


   g_signal_connect(window, "destroy",
        G_CALLBACK(gtk_main_quit), NULL);


  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_window_set_title(GTK_WINDOW(window), "GTK window");

  gtk_widget_show_all(window);

  gtk_main();

  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  //  rsvg_handle_get_geometry_for_element  (svg_handle, NULL, &viewport, NULL, NULL);

  return 0;
}
