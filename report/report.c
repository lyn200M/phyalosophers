/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:12:05 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/21 17:53:20 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "report.h"

void	report_log_error(char  *error_msg)
{
	printf("CHECK ARGS ERROR: %s\n", error_msg);
}

void	report_log_info(char  *info_msg)
{
	printf("INFO: %s\n", info_msg);
}
