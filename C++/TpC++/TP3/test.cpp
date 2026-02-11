# include <iostream>
# include <vector>
int min ( const std :: vector < int > & v )
{
int xmin = v . at (0);
for ( int x : v )
if ( x < xmin )
xmin = x ;
return xmin ;
}
int main ()
{
std :: cout << min ({7 ,3 ,5 ,2 ,9}) << std :: endl ;
return 0;
}

