# Parser un fichier binaire

## Enoncé

Un fichier `input.bin` vous est donné. 

Il s'agit d'un fichier purement binaire, contenant un flux d'information, et des données intelligibles qui servent à interpreter le flux d'information, ou donnent davantage de renseignements dessus.

Voici sa structure : 
1) Type de contenu, sto

| Début (octets) | Taille (octets) | Donnée        | endianness    | type de donné |
| :------------: | :-------------: | :-----------: | :-----------: | :-----------: |
| 0              | 8               | Type de média | big           | char*         |
| 9              | 4               | Format audio  | big           | char*         |
| 13             | 1               | Nb channels   | little        | u_int         |
| 14             | 4               | SampleRate    | little        | u_int         |
| 18             | 2               | Sample Size   | little        | u_int         |
| 20             | 64              | Titre         | big           | char*         |
| 84             | 32              | artiste       | big           | char*         |
| 116            | 8               | Longueur flux | little        | size_t        |
| 124            | X               | données audio | little        | X             |


### Inputs
Fichier binaire appelé `input.bin`.

### Outputs
Structure contenant les données du fichier.