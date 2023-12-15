# Norme Git

## Norme de commit

Les messages de commit doivent suivre la convention suivante :

`<type>[optional scope]: <description> | [optional footer]`

`<type>` : Le type de commit doit être l'un des suivants :
 - feat: une nouvelle fonctionnalité ajoutée
 - fix: une correction de bug
 - docs: une mise à jour de la documentation
 - style: une mise à jour de l'aspect visuel (pas de changement de fonctionnalité)
 - refactor: une modification du code qui n'ajoute pas de fonctionnalité ni ne corrige de bug
 - test: une modification des tests

`[optional scope]` : une section optionnelle qui peut être ajoutée pour fournir un contexte supplémentaire sur le commit.

`<description>` : un résumé concis et clair du commit en une phrase impérative.

`[optional footer]` : une section optionnelle pour fournir des informations supplémentaires telles que les références à des tickets de suivi de problèmes ou des problèmes connexes.

### Exemple : 

`feat(core): ajout d'une fonction de déplacement pour les pions | Fix #123`

## Norme de branches

`main` : branche principale contenant le code de production.

`develop` : branche de développement où les nouvelles fonctionnalités sont intégrées avant d'être déployées sur la branche main.

`feature/<module>/<description>` : branche de fonctionnalité pour ajouter une nouvelle fonctionnalité à un module spécifique. Les modules incluent core, graphique, et game. Les noms des branches de fonctionnalité doivent être descriptifs et inclure le type de fonctionnalité, par exemple `feature/core/add-pawn-movement`.

`hotfix/<description>` : branche de correctif pour corriger rapidement un bug dans la branche main. Les noms des branches de correctif doivent être descriptifs et inclure le numéro de ticket ou la description du bug, par exemple `hotfix/123-fix-login-issue`.
