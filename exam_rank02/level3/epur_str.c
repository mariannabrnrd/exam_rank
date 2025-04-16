/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:29:00 by mariaber          #+#    #+#             */
/*   Updated: 2025/04/16 10:29:06 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Nome dell'esercizio: epur_str
File attesi: epur_str.c
Funzioni permesse: write
Scrivi un programma che prende una stringa come argomento e la visualizza
con esattamente uno spazio tra ogni parola, senza spazi o tabulazioni all'inizio o alla fine,
seguita da una nuova riga.

Una "parola" è definita come una parte della stringa separata da spazi/tabulazioni
o dall'inizio/fine della stringa.

Se il numero di argomenti non è uguale a 1, oppure non ci sono parole da visualizzare,
il programma visualizza solo una nuova riga.

Esempi:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	space = 0;

	if (ac == 2)
	{
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i])
        {
            if (av[1][i] == ' ' || av[1][i] == '\t')
                space = 1;
            if (!(av[1][i] == ' ' || av[1][i] == '\t'))
            {
                if (space == 1)
                {
                    write(1, " ", 1);
                    space = 0;
                }
                write (1, &av[1][i], 1);
            }
            i++;
        }

    }
    write(1, "\n", 1);
    return (0);
}
