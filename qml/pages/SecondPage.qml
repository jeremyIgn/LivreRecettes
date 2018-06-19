import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    property var recette
    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    PageHeader {
        title: recette.Nom
        id: header
    }
    Flickable {
        anchors.top: header.bottom
        width: parent.width
        /*ScrollBar.vertical: ScrollBar {
                parent: flickable.parent
                anchors.top: flickable.top
                anchors.left: flickable.right
                anchors.bottom: flickable.bottom
            }*/
        Column {
        anchors.top:parent.bottom
        width: parent.width
        /*
        QString nom;
        int temps;
        int nombrePersonne;
        float note;
        QString description;
        QString image;
        */

        TextField {
            id: recetteNom
            label: "Nom de la recette"
            text: recette.Nom


            width: parent.width
            validator: RegExpValidator { regExp: /^[^/]*$/ }
            EnterKey.onClicked: {
                recette.Nom = recetteNom.text
                recetteTemps.focus = true
            }
            onFocusChanged: text = Qt.binding( function() { return recette.Nom} )
        }

        TextField {
            id: recetteTemps
            text: recette.Temps
            label: "Temps de réalisation (minutes)"
            width: parent.width
            validator: RegExpValidator { regExp: /\d{1,3}$/ }
            inputMethodHints: Qt.ImhDigitsOnly
            EnterKey.onClicked: {
                recette.Temps = recetteTemps.text
                recetteNombrePersonne.focus = true
            }
            onFocusChanged:  text = Qt.binding( function() { return recette.Temps} )
        }

        TextField {
            id: recetteNombrePersonne
            text: recette.NombrePersonne
            label: "Nombre de personnes"
            width: parent.width
            validator: RegExpValidator { regExp: /\d{1,2}$/ }
            inputMethodHints: Qt.ImhDigitsOnly
            EnterKey.onClicked: {
                recette.NombrePersonne = recetteNombrePersonne.text
                recetteNote.focus = true
            }
            onFocusChanged:  text = Qt.binding( function() { return recette.NombrePersonne} )
        }

        TextField {
            id: recetteNote
            text: recette.Note
            label: "Note"
            width: parent.width
            validator: RegExpValidator { regExp: /\d{1,2}$/ }
            inputMethodHints: Qt.ImhDigitsOnly
            EnterKey.onClicked: {
                recette.Note = recetteNote.text
                recetteDescription.focus = true
            }
            onFocusChanged:  text = Qt.binding( function() { return recette.Note} )
        }
        TextArea{
            id: recetteDescription
            text: recette.Description
            label: "Description"
            width: parent.width
            height: recetteNote.height * 3
            EnterKey.onClicked: {
                recette.Description = recetteDescription.text
                focus = false
            }
            onFocusChanged:  text = Qt.binding( function() { return recette.Description} )
        }


    }

}

}
