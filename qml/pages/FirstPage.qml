import QtQuick 2.0
import Sailfish.Silica 1.0
import RecetteModele 1.0
import "../delegate"
Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    // To enable PullDownMenu, place our content in a SilicaFlickable

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
        }

        model: RecetteModele {  monCarnet: monLivre }
        delegate: DelegateRecette { }
        VerticalScrollDecorator {}
    }
}

