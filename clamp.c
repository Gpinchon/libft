/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 17:08:11 by gpinchon          #+#    #+#             */
/*   Updated: 2015/12/23 12:32:14 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		clamp(float nbr, float max, float min)
{
	if (nbr >= max)
		return (max);
	else if (nbr <= min)
		return (min);
	else
		return (nbr);
}

long int	clamp_int(long int nbr, long int max, long int min)
{
	if (nbr >= max)
		return (max);
	else if (nbr <= min)
		return (min);
	else
		return (nbr);
}
