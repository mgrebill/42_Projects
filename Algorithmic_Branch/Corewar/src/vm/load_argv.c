/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:03:45 by smoreno           #+#    #+#             */
/*   Updated: 2018/05/02 18:03:45 by smoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char							*g_acceptable_flag_list[MAX_FLAGS] =
{
	"-n",
	"-dup",
	"-g",
	0
};

static int							g_flag_has_nbr[MAX_FLAGS] =
{
	1,
	1,
	0,
	0,
};

int									g_flags[MAX_FLAGS];
int									g_flag_nbrs[MAX_FLAGS];

static inline int					ft_strcmp(
	const char *s1,
	const char *s2)
{
	while (*s1 == *s2 && *s1 && s1++ && s2++)
		;
	return (*s1 - *s2);
}

static inline int					ft_atoi(
	const char *str)
{
	int								nbr;

	nbr = 0;
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + *str++ - '0';
	return (nbr);
}

static inline uint64_t				get_free_champ_pid(void)
{
	uint8_t							not_first;
	uint64_t						pid;
	t_process						*cur_process;

	pid = 1;
	not_first = 0;
	if (g_vm.last_process)
	{
		cur_process = g_vm.last_process->next;
		while (cur_process->previous != g_vm.last_process || !not_first++)
		{
			if (cur_process->creator->pid == pid)
			{
				cur_process = g_vm.last_process;
				not_first = 0;
				pid++;
			}
			cur_process = cur_process->next;
		}
	}
	return (pid);
}

static inline uint64_t				get_champ_pid(void)
{
	uint8_t							not_first;
	uint64_t						pid;
	t_process						*cur_process;

	not_first = 0;
	pid = 0;
	if (g_flags[FLAG_CHAMP_NUM])
	{
		pid = g_flag_nbrs[FLAG_CHAMP_NUM];
		g_flags[FLAG_CHAMP_NUM] = 0;
		not_first = 0;
		if (g_vm.last_process)
		{
			cur_process = g_vm.last_process->next;
			while (cur_process->previous != g_vm.last_process || !not_first++)
			{
				if (cur_process->creator->pid == pid)
					pid = 0;
				cur_process = cur_process->next;
			}
		}
	}
	if (!pid)
		pid = get_free_champ_pid();
	return (pid);
}

void								load_argv(
	const int argc,
	const char *const restrict *const restrict argv)
{
	int								e;
	int								i;

	if (argc < 2)
		exit(write(1, ERROR_USAGE, sizeof(ERROR_USAGE) - 1));
	e = 1;
	while (e < argc)
	{
		i = -1;
		while (g_acceptable_flag_list[++i])
			if (!ft_strcmp(argv[e], g_acceptable_flag_list[i]))
			{
				g_flags[i] = 1;
				if (e < argc && g_flag_has_nbr[i])
					g_flag_nbrs[i] = ft_atoi(argv[++e]);
				break ;
			}
		if (!g_acceptable_flag_list[i])
			g_vm.nb_champs = load_champ(argv[e], get_champ_pid());
		++e;
	}
	if (!g_vm.last_process)
		exit(write(1, ERROR_NO_CHAMP, sizeof(ERROR_NO_CHAMP) - 1));
}
