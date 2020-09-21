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
| 13             | 2               | Nb channels   | little        | u_int16       |
| 14             | 4               | Fq echantill. | little        | u_int32       |
| 18             | 2               | Taille sample | little        | u_int16       |
| 20             | 64              | Titre         | big           | char*         |
| 84             | 32              | Artiste       | big           | char*         |
| 116            | 8               | Longueur flux | little        | size_t        |
| 124            | X               | données audio | little        | X             |


### Inputs
Fichier binaire appelé `input.bin` présent dans le repertoire courant.
Un pointeur vers une instance de struct `ParsedBinary` qu'il faut completer.

### Outputs
Structure dont le pointeur est passé en paramètre, contenant les données du fichier:

```cpp
struct ParsedBinary {
    char* mediaType,
    char* audioFormat,
    unsigned short nb_channels,
    unsigned int sample_rate,
    unsigned short sample_size,
    char* title,
    char* artist,
    size_t buffer_length,
    char* buffer
};
```


## Conseils

patience....