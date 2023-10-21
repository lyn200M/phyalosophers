/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:42:16 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/21 19:36:55 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int ac, char **av)
{
	if (!is_good_argument(ac, av))
		return (0);
	report_log_info(CHECK_ARGS_OK_LOG);
	return(0);
}

bool	is_good_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		report_log_error(NUMBER_ARGUMENTS_ERROR);
		return (false);
	}
	if (!is_all_number(av))
	{
		report_log_error(ARGUMENTS_NOT_NUMBER_ERROR);
		return (false);
	}
	return (true);
}

/**
 * soit Tm = temps de manger
 * soit Td = temps de dormir
 * soit TM = temps au bout duquel il meurt s'il ne mange pas
 * soit Np = nombre de phylosophes et de fourchette
 * chaque philosophe mange avec 2 fourchette. IL partage chque fourcheete avec
 * un autre philosophe
 *
 */
