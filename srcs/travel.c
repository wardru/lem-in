#include "lem_in.h"

void	go_throught_paths(t_env *lem)
{
	static size_t	ants_id_pick;
	unsigned char	print;
	t_path	*paths_tmp;
	t_rlist	*lst_tmp;

	paths_tmp = lem->paths;
	while (paths_tmp)
	{
		lst_tmp = paths_tmp->lst;
		while (lst_tmp->next)
		{
			print = 0;
			if (lst_tmp->r->has_ant == 0 && ft_strequ(lst_tmp->next->r->name, lem->start->r->name))
			{
				if (lem->start->r->has_ant <= 0)
					break;
				lst_tmp->r->has_ant++;
				lst_tmp->r->ant_id = ++ants_id_pick;
				lem->start->r->has_ant--;
				print = 1;
			}
			else if (ft_strequ(lst_tmp->r->name, lem->end->r->name) && lst_tmp->next->r->has_ant == 1)
			{
				lst_tmp->r->ant_id = lst_tmp->next->r->ant_id;
				lst_tmp->r->has_ant++;
				lst_tmp->next->r->has_ant--;
				print = 1;
			}
			else if (lst_tmp->r->has_ant == 0 && lst_tmp->next->r->has_ant == 1)
			{
				lst_tmp->r->ant_id = lst_tmp->next->r->ant_id;
				lst_tmp->r->has_ant++;
				lst_tmp->next->r->has_ant--;
				print = 1;
			}
			if (print)
				ft_printf("L%d-%s ", lst_tmp->r->ant_id, lst_tmp->r->name);
			lst_tmp = lst_tmp->next;
		}
		ft_printf("\n");
		paths_tmp = paths_tmp->next;
	}
}

void	travel_multipath(t_env *lem)
{
	lem->start->r->has_ant = lem->ants_nb;
	while (lem->end->r->has_ant != lem->ants_nb)
		go_throught_paths(lem);
}

void	travel_direct(t_env *lem)
{
	size_t	i;
	
	i = 1;
	while (i <= lem->ants_nb)
	{
		ft_printf("L%d-%s", i, lem->end->r->name);
		if (i != lem->ants_nb)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

void	travel_ants(t_env *lem)
{
	if (lem->direct)
		travel_direct(lem);
	else
		travel_multipath(lem);
}
