//this file stores all the variables and has the funcitons to read and write them. Or at least in the future it will do it.
int buf;
int pos_x,pos_y;
int field[1000][1000];
int buildings[100000];
unsigned long int max_logistics_power;
int items[1000];
unsigned long long int store_place;
unsigned long long int stored_items;
unsigned long long int money;
unsigned long long int power_max;
unsigned long long int power_used;
int item_use[1000];
int item_calc[1000];
unsigned int sell_ammount[10000];
//items
int item_costs[1000];
int item_uses[1000];
int item_prods[1000];
char item_names[50000];
int items_cnt;
int items_max_produced[1000],items_max_used[1000];
//buildings
char building_names[600000];
int prod[100000];
int prodspeed[100000];
int power_us[100000];
int building_costs[100000];
int uses_1[100000];
int uses_2[100000];
int uses_3[100000];
int ammount_1[100000];
int ammount_2[100000];
int ammount_3[100000];
int ascii[100000];
int storage_p[100000];
int power_p[100000];
int buildings_exists[100000];

int item_cost_get(int id)
{
	return item_costs[id];
}
int render=false;
int input_buffer_get()
{
	return buf;
}
int input_buffer_store(int a)
{
	buf=a;
	return buf;
}
int input_buffer_clear()
{
	buf=0;
	return 0;
}
int player_pos_set(int x,int y)
{
	pos_x=x;
	pos_y=y;
	return pos_x+pos_y;
}
int player_pos_get_y()
{
	return pos_y;
}
int player_pos_get_x()
{
	return pos_x;
}

int logistics_power_set(int a)
{
	max_logistics_power=a;
}

int logistics_power_get()
{
	return max_logistics_power;
}
