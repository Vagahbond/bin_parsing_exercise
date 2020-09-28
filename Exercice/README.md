# Consigne

Un fichier contenant de l'audio compressé vous est donné. L'objectif est de parser les headers du fichier binaire, afin de connaitre la taille du fichier et la méthode de compression qui a été utilisée. Ces valeurs vous permettrons ensuite de décompresser le buffer de données de son. Vous devez renvoyer ces informations par la suite dans une structure semblable à la suivante.


Voici la structure du fichier binaire : 

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

La conversion entre les types des pointeurs sera d'une grande utilité.

Le buffer de données à la fin du fichier n'est pas a interpreter, le seul facteur important est la conservation de son integrité.

Cependant si vous disposez de Audacity vous pourrez extraire dans un fichier à part ce buffer et l'ecouter en utilisant la fonction "raw audio data" dans "fichier" -> "import", et en renseignant les bons paramètres.