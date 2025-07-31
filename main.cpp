#include "MainWindow.hpp"
#include <gtkmm.h>
#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create("com.aydinkasimoglu.cmtparser");

    app->signal_activate().connect([&app]() {
        try {
            auto mainWindowController = std::make_shared<MainWindow>();
            auto pWindow = mainWindowController->get_window();

            if (pWindow) {
                app->add_window(*pWindow);
                pWindow->present();
                
               
                pWindow->signal_close_request().connect(
                    [&app, mainWindowController]() -> bool {
                        app->quit();
                        return false;
                    }, 
                    false 
                );
            }
        }
        catch(const std::exception& e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
        }
    });

    return app->run(argc, argv);
}