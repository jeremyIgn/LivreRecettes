import QtQuick 2.0
import Sailfish.Silica 1.0
import "../pages"


ListItem {
    id: recetteItem
    width: listView.width
    menu: ContextMenu {
        MenuItem {
            text: "Supprimer de la liste"
            onClicked: listView.model.supprimerRecette(index)
        }

    }

    Label {
        text: Nom
    }

    onClicked: pageStack.push( recettePage, { recette: Recette }  )
    Component {
        id: recettePage
        SecondPage {}
    }
}
