#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "useful.h"


int existing_nodes = 0;
int existing_lists = 0;

Node node_new(Node next, Node prev, void *v, int (*free)(void *), int (*_print)(void *))
{
  static int i = 1;
  Node new;

  if(NULL == (new = calloc(1, sizeof(struct _node))))
  {
    return NULL;
  }

  if(existing_nodes == 0) i = 1;

  new->next = next;
  new->prev = prev;
  new->v = v;
  new->free = free;
  new->print = _print;
  new->id = i++;
  new->n = 0;
  memset(new->str, 0, str_size);

  existing_nodes++;

  return new;
}


int node_kill(Node n)
{
  int result = failure;

  if(NULL == n)
  {
    return got_null;
  }

  existing_nodes--;


  if(NULL != n->free && NULL != n->v)
  {
    result = n->free(n->v);
  }
  else
  {
    result = success;
  }

  n->next = NULL;
  n->prev = NULL;
  n->free = NULL;
  n->print = NULL;
  n->v = NULL;
  n->n = 0;
  memset(n->str, 0, str_size);

  free(n);

  return result;
}


List list_new()
{
  static int i = 1;
  List l;

  if(NULL == (l = calloc(1, sizeof(struct _list))))
  {
    return NULL;
  }

  if(existing_lists == 0) i = 1;

  l->root = NULL;
  l->current = NULL;
  l->size = 0;
  l->id = i++;
  memset(l->name, 0, str_size);

  existing_lists++;

  return l;
}


int list_kill(List l)
{
  if(NULL == l)
  {
    return got_null;
  }


  existing_lists--;

  l->current = l->root;
  while(got_null != list_remove(l));

  l->root = NULL;
  l->current = NULL;
  l->size = 0;
  l->id = 0;
  memset(l->name, 0, str_size);

  free(l);

  return success;
}


int list_add_front(List l, Node n)
{
  if(NULL == l || NULL == n)
  {
    return got_null;
  }

  n->next = l->root;

  if(NULL != l->root)
    l->root->prev = n;
  l->root = n;


  l->size += 1;
  if(1 == l->size)
    l->current = l->root;

  return success;
}


int list_add_back(List l, Node n)
{
  Node temp = NULL;

  if(NULL == l || NULL == n)
  {
    return got_null;
  }

  if(NULL == l->root)
  {
    l->root = n;
    l->current = l->root;
  }
  else
  {
    temp = l->current;  
    l->current = l->root;

    while(l->current->next != NULL)
    {
      l->current = l->current->next;
    }

    l->current->next = n;
    n->prev = l->current;
    l->current = temp;
  }

  l->size += 1;

  return success;
}


int list_add_before(List l, Node n)
{
  if(NULL == l || NULL == n)
  {
    return got_null;
  }

  if(l->current == l->root)
  {
    list_add_front(l, n);
  }
  else
  { 
    n->next = l->current;
    n->prev = l->current->prev;
    n->prev->next = n;
    l->current->prev = n;
  }

  return success;
}


int list_add_after(List l, Node n)
{
  if(NULL == l || NULL == n)
  {
    return got_null;
  }

  if(NULL == l->current || NULL == l->current->next)
  {
    list_add_back(l, n);
  }
  else
  {
    n->prev = l->current;
    n->next = l->current->next;
    n->next->prev = n;
    l->current->next = n;
  }

  return success;
}


int list_remove(List l)
{
  Node temp;

  if(NULL == l || NULL == l->root)
  {
    return got_null;
  }

  if(NULL == l->current)
  {
    return is_null;
  }

  if(l->current == l->root)
  {
    l->root = l->current->next;
    node_kill(l->current);
    l->current = l->root;

    if(NULL != l->current)
      l->current->prev = NULL;
  }
  else
  {
    temp = l->current;
    l->current->prev->next = l->current->next;
    l->current = l->current->prev;
    node_kill(temp);

    if(l->current->next != NULL)
      l->current->next->prev = l->current;
  }

  l->size -= 1;

  return success;
}


int list_root(List l)
{
  if(NULL == l || NULL ==  l->root)
  {
    return got_null;
  }

  l->current = l->root;

  return success;
}


int list_tail(List l)
{
  if(NULL == l || NULL ==  l->root)
  {
    return got_null;
  }

  while(success == list_next(l));

  return success;
}


int list_next(List l)
{
  int status = unset;

  if(NULL == l)
  {
    status = got_null;
  }

  if(unset == status && NULL == l->current)
  {
    status = is_null;
  }

  if(unset == status && NULL == l->current->next)
  {
    status = null_next;
  }

  if(unset == status || unset == null_next)
  {
    status = success;
    l->current = l->current->next;
  }

  return status;
}


int list_prev(List l)
{
  int status = unset;

  if(NULL == l)
  {
    status = got_null;
  }

  if(unset == status && NULL == l->current)
  {
    status = is_null;
  }

  if(unset == status && NULL == l->current->prev)
  {
    status = null_next;
  }

  if(unset == status || null_next == status)
  {
    status = success;
    l->current = l->current->prev;
  }

  return status;
}


Node list_get(List l)
{
  if(NULL == l || NULL == l->current)
  {
    return NULL;
  }

  return l->current;
}

int list_print(List l)
{
  Node temp;
  printf("list has %d elements\n", l->size);

  if(NULL == l || NULL == l->current)
  {
    return got_null;
  }

  temp = l->current;
  l->current = l->root;
  while(l->current != NULL)
  {
    printf("-%d-\n", l->current->id);
    l->current = l->current->next;
  }
  l->current = temp;

  return success;
}
