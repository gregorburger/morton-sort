#include "mainwindow.h"
#include <QApplication>

#include "morton.h"

int main(int argc, char *argv[]) {
#if 1
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
#else
    std::vector<vector> v(10000000);
    gen_random(v);

    morton_sort(v);
#endif
}
