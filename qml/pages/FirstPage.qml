import QtQuick 2.0
import Sailfish.Silica 1.0
import RecetteModele 1.0
import "../delegate"
Page {
    id: page
    allowedOrientations: Orientation.All

    SilicaListView {
        id: listView
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Mes Recettes")
        }

        PullDownMenu {
            MenuItem {
                text: qsTr("Ajouter recette")
                onClicked: listView.model.ajouterRecette()
            }
            MenuItem {
                text: qsTr("Sauvegarde en JSON")
                onClicked: listView.model.sauvegarder()
            }
        }

        model: RecetteModele {  monCarnet: monLivre }
        delegate: DelegateRecette { }
        VerticalScrollDecorator {}
    }
}

