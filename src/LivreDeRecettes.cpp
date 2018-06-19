#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif
#include "modeles/recettemodele.h"
#include "donnees/carnetrecettes.h"
#include "donnees/recette.h"
#include <sailfishapp.h>
#include <QQuickView>
#include <QtQml>

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/LivreDeRecettes.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    QGuiApplication* app = SailfishApp::application(argc, argv);
    QQuickView *view  = SailfishApp::createView();

    QLoggingCategory::setFilterRules(QStringLiteral("qt.qml.binding.removal.info=true"));

    qmlRegisterType<RecetteModele>("RecetteModele", 1, 0, "RecetteModele");
    qmlRegisterUncreatableType<CarnetRecettes>("RecetteModele", 1, 0, "CarnetRecettes", QStringLiteral("Don't define CarnetRecettes in QML!!") );
    qmlRegisterUncreatableType<Recette>("RecetteModele", 1, 0, "Recette", QStringLiteral("Don't define Recette in QML!!") );

    CarnetRecettes modele;

    Recette *recette = new Recette("Gateau au chocolat");
    Recette *recette2 = new Recette("Tarte au citron");

    modele.ajouterRecette(recette);
    modele.ajouterRecette(recette2);

    view->rootContext()->setContextProperty("monLivre", &modele);

    view->setSource(SailfishApp::pathTo("qml/LivreDeRecettes.qml"));
    view->show();

    return app->exec();
}
