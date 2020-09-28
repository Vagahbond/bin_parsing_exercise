# Contexte

Vous êtes de retour en 2010, et vous voulez écouter de la musique. Pas encore de smartphones avec Deezer ou Apple Music à cette époque. Il ne vous reste plus que votre petit MP3 en forme de clef USB, avec 200 MB de mémoire! Afin d'économiser de l'éspace, vous decidez de réduire la taille de vos musiques, quitte à y perdre de la qualité. 

# Consigne
Déchiffrez les entêtes du fichier fourni afin d'obtenir sa fréquence d'échantillonage et la taille que représente un sample. Puis, pour chaque sample dans le buffer, réduire sa taille de moitié. Il est possible proceder en créant un nouveau buffer.

Diviser par deux la taille de chaque sample aura une influence sur sa taille maximum: 
Si l'on effectue cette operation sur des samples de 16 bits chacun afins qu'ils ne fassent plus que 8 bits, on passe les valeurs minimum et maximum de 


## Input
Fichier au format WAV

## Output
Une structure contenant le nouveau buffer de données audio, et les valeurs permettant de le lire, selon la déclaration suivante :

```C
struct audio_data
{
    short sample_size;
    short nb_channels;
    short sample_rate;
    size_t buffer_length;
    char* audio_buffer;
};
```

## Resources

### Structure du fichier 




### Liens de documentation
[Cannonical wav description](http://soundfile.sapp.org/doc/WaveFormat/)

[Other description](http://www.lightlink.com/tjweber/StripWav/Canon.html)

[Endianness](https://en.wikipedia.org/wiki/Endianness)

# Pour aller plus loin

Pour entendre le resultat de votre algorithme vous pouvez telecharger le fichier sur [ce lien](), et tenter d'y appliquer votre code. Il est ensuite possible de faire un dump du vuffer seul, et de l'ecouter avec la fonction d'import de fichiers audio brut sur Audacity. L'`encoding` est déterminé par la taille d'un sample multiplié par le nombre de channels.