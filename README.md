# Linked List #
Linked List operations

--------------------------------------------------------------------------------

## Contenu ##
Ce programme est centré sur les Liste Chaînée, et réalise des opération simple dessus. Pour voire les fonctions implémenté, voir le fichier `list.h`. Certaines fonctions ne sont pas complétement tester, reportez moi les bug que vous trouvez.
Ce code source est sous licence GNU (voir `LICENCE`).

![Illustration d'une liste chaînée sur Openclassrooms.com](https://user.oc-static.com/files/396001_397000/396275.png)

_[Illustration d'une liste chaînée sur Openclassrooms.com](https://openclassrooms.com/courses/apprenez-a-programmer-en-java/les-collections-d-objets "Illustration d'une liste chaînée sur Openclassrooms.com")_

### Note ###
Le `Makefile` est fait pour compiler sous Linux (comme sur Turing par exemple). Il comporte des commandes de Linux comme `ar`, utilisé pour créer une librairie statique en C exclusive à Linux.

--------------------------------------------------------------------------------

## Description ##
* `list.h`: Liste des prototypes des fonctions sur les listes chaînées, et définition du type `Cell` et `List`.
* `list.c`: Implémentations des fonctions de `list.c`.
* `main.c`: Un exemple d'utilisation.
* `example`: Executable Linux (compilé sous Turing avec `gcc`)
* `boolean.h`: Implémentation du type booléen en C (il n'existe pas de base).
* `README.MD`: Ce fichier.
* `LICENCE`: Fichier texte sur la licence du code source.

--------------------------------------------------------------------------------

## Liste des fonctions dans la bibliothèque list ##
### Note sur les pointeurs ###
__**Attention:**__ Dans le cas ou l'utilisateur manipule un pointeur de list (`List*`), il faut faire très attention à ce que le pointeur **ne soit pas égale à `NULL`** lors de l'utilisation des fonctions çi-dessous. En effet, toutes ces fonctions prennant comme entré un pointeur de liste (tel que `list_new`, `list_add`, etc...), un `assert` verifiera que la liste passée en argument est bien différent de `NULL`. En d'autre terme, si vous entrez un pointeur nul dans l'une de ces fonctions, votre programme s'arrêtera et une exception sera levée.

### Constructeur ###
* `void list_new(List* l)`: Initialise la tête à `NULL`.

### Destructeur ###
* `void list_delete(List* l)`: Supprime la liste passée en argument de la mémoire. Toutes les cellules sont supprimés une par une.

### Accesseurs ###
* `int list_length(List l)`: Renvoie le nombre de cellule de la liste donnée en argument. Si la liste est vide (la tête égale à `NULL`), la fonction renvoie 0.
* `Cell* list_head(List l)`: Renvoie l'adresse de la première cellule. **Attention: Cette fonction ne doit pas être utilisée en dehors de cette biliothèque, car elle est de bas niveau** (les cellules ne doivent pas être manipuler à l'extérieur, car l'utilisateur n'est pas censé connaître cette structure).
* `Cell* list_tail(List l)`: Renvoie l'adresse de la dernière cellule d'une liste, de telle sorte que cette cellule ai la propriété suivante :
```C
cell->next = NULL;
```
**Attention: Cette fonction ne doit pas être utilisée en dehors de cette biliothèque, car elle est de bas niveau.**
* `Cell* list_getCell(List l, int index)`: Renvoie l'adresse de la cellule de la liste l à l'index donné. Si l'index est incorrecte (inférieur à 0 ou supérieur à la taille maximale de la liste), la fonction renvoie `NULL` (rappel: `NULL` n'est pas un _nombre_ mais un **pointeur** !!!). **Attention: Cette fonction ne doit pas être utilisée en dehors de cette biliothèque, car elle est de bas niveau.**
* `int list_get(List l, int index)`: Renvoie la valeur de la cellule positionnée à l'index `index` dans la liste `l`. Si l'index est incorrecte, la liste renvoie 0 (à remplacer par une valeur plus significative, comme une exception peut-être...).
* `bool list_contains(List l, int value)`: Renvoie `true` (_vrai_) si la valeur `value` existe dans la liste `l`. Sinon renvoie `false` (_faux_).

### Mutateurs ###
* `void list_add(List* l, int value)`: Ajoute en toute dernière position la valeur `value` à la liste `l`. La cellule créée devient ainsi la queue de la liste. Si la liste l est vide, alors la cellule créée est à la fois la tête et la queue de la liste.
* `bool list_addAt(List* l, int index, int value)`: Ajoute la valeur `value` à la liste `l` à l'index `index`. Si l'index est incorrecte, cette fonction ne fait rien. À noter qu'on peut utiliser cette fonction sur une liste vide avec `index = 0`.
* `bool list_remove(List* l, int index)`: Supprime la valeur à l'indice `index` à la liste `l`. Si l'index est incorrecte, cette fonction ne fait rien.
* `bool list_removeAll(List* l)`: Supprime toutes les valeurs de la liste `l`, et instancie la tête à la valeur `NULL`.
* `bool list_set(List* l, int index, int value)`: Change la valeur à l'indice `index` à `value` dans la liste `l`. Si l'index est incorrecte, cette fonction ne fait rien.

### Autres ###
* `int* listToArray(List l)`: Renvoie l'adresse tableau associé à la liste `l`. Par exemple, si `l = <1, 9, 6, 5>`, on a `listToArray(l) = [1, 9, 6, 5]`. **Attention, cette fonction n'a pas été testée !!!**
* `void listFromArray(List* l, int* array, int n)`: Fonction réciproque de `int* listToArray(List l)` : crée une liste `l` à partir d'une adresse de tableau `l`. L'argument `n` est la taille du tableau donnée en argument. **Attention, cette fonction n'a pas été testée !!!**
* `void list_sort(List *l)`: Tri la liste `l` en ordre croissant. Si la liste est vide, cette fonction ne fait rien.
* `void list_print(List l)`: Affiche la liste `l` dans la sortir standard (_`stdout`_) sous le format `[%s, %s, %s, ..., %s]` (avec `%s` étant les valeur de la liste `l` de `0` à `list_length(l)-1`.
