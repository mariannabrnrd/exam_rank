/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:12:50 by mariaber          #+#    #+#             */
/*   Updated: 2025/04/05 14:12:54 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char res = 0x0;  //inizializziamo il risultato a 0
    int i = 0;

    while(i < 8)        //cicliamo i bit partendo da 0
    {
        res = res << 1; //spostiamo a sinistra i bit gia presenti nel risultato 
        res = res | (octet & 1); //prendo l'ultimo bit e lo metto nella posizione libera di res
        octet = octet >> 1; //elimina l'ultimo bit, spostando tutto a destra
        i++;
    }
    return(res);
}

int main (void)
{
    unsigned char num = 48;

    printf("numero -> %u\n", num);
    num = reverse_bits(num);
    printf("binario invertito -> %u\n", num);
    return(0);
}

