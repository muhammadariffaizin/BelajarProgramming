#include<stdio.h>
#include<stdlib.h>

int randVal;
int randOffset;
int modular;

struct Entity{
	int id;
	int HP;
	int ATK;
	int DEF;
	int MAG;
	int SPD;
	int act;
	int isHaste;
	struct Entity* next;
};

struct Action{
	int type;
	int id;
	int damage;
	int actionMessage;
	int priority;
	struct Action* next;
};

struct Entity* player;
struct Entity* enemy;
struct Action* actionQueue;

void initRand(){
	randVal = 0;
	randOffset = 3651;
	modular = 31627;
}

int nextVal(){
	randVal += randOffset;
	randVal *= randOffset;
	randVal %= modular;
	
	return randVal;
}

struct Entity* newEntity(int id, int newHP, int newATK, int newDEF, int newMAG, int newSPD)
{
	struct Entity* entity = (struct Entity*)malloc(sizeof(struct Entity));
	entity->id = id;
	entity->HP = newHP;
	entity->ATK = newATK;
	entity->DEF = newDEF;
	entity->MAG = newMAG;
	entity->SPD = newSPD;
	entity->act = nextVal()%31;
	entity->isHaste = 0;
	entity->next = NULL;
	
	return entity;
}

struct Action* newAction(int type, int id, int damage, int actionMessage, int priority){
	struct Action* action = (struct Action*)malloc(sizeof(struct Action));
	action->type = type;
	action->id = id;
	action->damage = damage;
	action->actionMessage = actionMessage;
	action->priority = priority;
	action->next = NULL;
	
	return action;
}

void pushChar(struct Entity** stack, int id, int newHP, int newATK, int newDEF, int newMAG, int newSPD)
{
	struct Entity* entity = newEntity(id, newHP, newATK, newDEF, newMAG, newSPD);
	
	if((*stack) == NULL)
	{
		entity->next = NULL;
		*stack = entity;
		return;
	}
	
	if(entity->SPD < (*stack)->SPD)
	{
		entity->next = *stack;
		*stack = entity;
		return;
	}
	else if((*stack)->next == NULL)
	{
		entity->next = (*stack)->next;
		(*stack)->next = entity;
		return;
	}
	
	struct Entity* temp = *stack;
	
	while(temp->next != NULL)
	{	
		if(temp->next == NULL)
			break;
		
		if(entity->SPD > temp->next->SPD)
			temp = temp->next;
		else
			break;
	}
	
	entity->next = temp->next;
	temp->next = entity;
	
	return;
}

void popChar(struct Entity** entity)
{
	if(*entity == NULL)
		return;
	struct Entity* temp = *entity;
	if(temp->next == NULL)
		*entity = NULL;
	else
		*entity = temp->next;
	free(temp);
}

void pushAct(struct Action** stack, int type, int id, int damage, int actionMessage, int priority){
	struct Action* action = newAction(type, id, damage, actionMessage, priority);
	
	if((*stack) == NULL)
	{
		action->next = NULL;
		*stack = action;
		return;
	}
	
	if(action->priority < (*stack)->priority)
	{
		action->next = *stack;
		*stack = action;
		return;
	}
	else if((*stack)->next == NULL)
	{
		action->next = (*stack)->next;
		(*stack)->next = action;
		return;
	}
	
	struct Action* temp = *stack;
	
	while(temp->next != NULL)
	{	
		if(temp->next == NULL)
			break;
		
		if(action->priority > temp->next->priority)
			temp = temp->next;
		else
			break;
	}
	
	action->next = temp->next;
	temp->next = action;
	
	return;
}

void popAct(struct Action** action)
{
	if(*action == NULL)
		return;
	struct Action* temp = *action;
	if(temp->next == NULL)
		*action = NULL;
	else
		*action = temp->next;
	free(temp);
}

int calcPhysic(int atk, int def){
	int damage = atk - def;
	if(damage < 1)
		return 0;
	
	damage *= (nextVal()%21 + 90);
	damage /= 100;
	
	if(nextVal()%100 < 30)
		damage *= 3;
	
	return damage;
}

int calcMagic(int mag){
	int damage = mag;
	damage *= (nextVal()%61 + 70);
	damage /= 100;
	
	return damage;
}

void updatePlayer(){
	struct Entity* temp = player;
	
	while(temp != NULL){
		if(temp->isHaste == 1)
			temp->act += temp->SPD * 2;
		else
			temp->act += temp->SPD;
		
		if(temp->act > 99){
			temp->isHaste = 0;
			int action = nextVal()%100;
			int actionMessage;
			int damage = 0;
			
			if(action < 70){
				if(temp->ATK < enemy->DEF + 1){
					damage = calcMagic(temp->MAG);
					actionMessage = 1;
				} else{
					damage = calcPhysic(temp->ATK, enemy->DEF);
					actionMessage = 2;
				}
			} else if(action < 95){
				damage = calcMagic(temp->MAG) * 9;
				actionMessage = 3;
			} else{
				temp->isHaste = 1;
				actionMessage = 4;
			}
			
			pushAct(&actionQueue, 1, temp->id, damage, actionMessage, temp->act - 100);
			temp->act -= 100;
		}
		
		temp = temp->next;
	}
}

void updateEnemy(){
	struct Entity* temp = enemy;
	
	while(temp != NULL){
		if(temp->isHaste == 1)
			temp->act += temp->SPD * 2;
		else
			temp->act += temp->SPD;
		
		if(temp->act > 99){
			temp->isHaste = 0;
			int action = nextVal()%100;
			int actionMessage;
			int damage = 0;
			
			if(action < 70){
				if(temp->ATK < player->DEF + 1){
					damage = calcMagic(temp->MAG);
					actionMessage = 1;
				} else{
					damage = calcPhysic(temp->ATK, player->DEF);
					actionMessage = 2;
				}
			} else if(action < 95){
				damage = calcMagic(temp->MAG) * 9;
				actionMessage = 3;
			} else{
				temp->isHaste = 1;
				actionMessage = 4;
			}
			
			pushAct(&actionQueue, 2, temp->id, damage, actionMessage, temp->act - 100);
			temp->act -= 100;
		}
		
		temp = temp->next;
	}
}

void updateQueue(){
	struct Action* temp = actionQueue;
	
	while(temp != NULL){
		if(player == NULL || enemy == NULL)
			break;
		if(temp->type == 1){
			if(temp->actionMessage == 4){
				printf("Player %d cast Haste!\n", temp->id);
			} else{
				switch(temp->actionMessage){
					case 1: printf("Player %d menyerang menggunakan Magic! ", temp->id); break;
					case 2: printf("Player %d menyerang menggunakan senjatanya! ", temp->id); break;
					case 3: printf("Player %d menyerang menggunakan Ultimate Magic! ", temp->id); break;
				}
				enemy->HP -= temp->damage;
				printf("Menghasilkan %d damage ke Enemy %d!\n", temp->damage, enemy->id);
				
				if(enemy->HP < 1){
					printf("Enemy %d telah dikalahkan!\n", enemy->id);
					enemy = enemy->next;
				}
			}
		} else if(temp->type == 2){
			if(temp->actionMessage == 4){
				printf("Enemy %d cast Haste!\n", temp->id);
			} else{
				switch(temp->actionMessage){
					case 1: printf("Enemy %d menyerang menggunakan Magic! ", temp->id); break;
					case 2: printf("Enemy %d menyerang menggunakan senjatanya! ", temp->id); break;
					case 3: printf("Enemy %d menyerang menggunakan Ultimate Magic! ", temp->id); break;
				}
				player->HP -= temp->damage;
				printf("Menghasilkan %d damage ke Player %d!\n", temp->damage, player->id);
				
				if(player->HP < 1){
					printf("Player %d tumbang...\n", player->id);
					player = player->next;
				}
			}
		}
		temp = temp->next;
	}
	
	while(actionQueue != NULL)
		popAct(&actionQueue);
}


int main(){
	int P, E;
	int HP, ATK, DEF, MAG, SPD;
	initRand();
	scanf("%d %d", &P, &E);
	
	player = NULL;
	enemy = NULL;
	
	for(int p=0; p<P; p++){
		scanf("%d %d %d %d %d", &HP, &ATK, &DEF, &MAG, &SPD);
		pushChar(&player, p+1, HP, ATK, DEF, MAG, SPD);
	}
	
	for(int e=0; e<E; e++){
		scanf("%d %d %d %d %d", &HP, &ATK, &DEF, &MAG, &SPD);
		pushChar(&enemy, e+1, HP, ATK, DEF, MAG, SPD);
	}
	
//	printStack(&player);
//	printStack(&enemy);
	
	while(player != NULL && enemy != NULL){
		updatePlayer();
		updateEnemy();
		updateQueue();
	}
	
//	while(player != NULL)
//		pop(&player);
	
	if(player == NULL)
		printf("Game Over.\n");
	else if(enemy == NULL)
		printf("You Won!\n");
}
