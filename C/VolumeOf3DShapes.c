#define PI 3.142
#include<stdio.h>

void VolumeCuboid();
void VolumeCylinder();
void VolumePrism();
void VolumeSphere();
void VolumePyramid();
void VolumeRightCone();
void VolumeTetrahedron();

void main()
{
	int c;printf("Volume of \n1.Cuboid\n2.Cylinder\n3.Prism\n4.Sphere\n5.Pyramid\n6.Right Circular Cone\n7.Tetrahedron\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1: VolumeCuboid();break;
		case 2: VolumeCylinder();break;
		case 3: VolumePrism();break;
		case 4: VolumeSphere();break;
		case 5: VolumePyramid();break;
		case 6: VolumeRightCone();break;
		case 7: VolumeTetrahedron();break;
		default:printf("Invalid input");
	}
}
void VolumeCuboid()
{
printf("Input sides of cubiod\n");
float l,b,h;
scanf("%f %f %f",&l,&b,&h);
printf("Volume of cuboid = %.2f",l*b*h);
}
void VolumeCylinder()
{
printf("Input radius and height of cylinder\n");
float r,h;
scanf("%f %f",&r,&h);
printf("Volume of cylinder = %.2f",PI*r*r*h);
}
void VolumePrism()
{
printf("Input area of base and height of prism\n");
float a,h;
scanf("%f %f",&a,&h);
printf("Volume of prism = %.2f",a*h);
}
void VolumeSphere()
{
printf("Input radius of sphere\n");
float r;
scanf("%f",&r);
printf("Volume of sphere = %.2f",PI*r*r*r*(4/3));
}
void VolumePyramid()
{
printf("Input area of base and height of pyramid\n");
float a,h;
scanf("%f %f",&a,&h);
printf("Volume of pyramid = %.2f",a*h*(1.0/3));
}
void VolumeRightCone()
{
printf("Input radius of circular base and height of cone\n");
float r,h;
scanf("%f %f",&r,&h);
printf("Volume of cylinder = %.2f",PI*r*r*h*(1.0/3));
}
void VolumeTetrahedron()
{
printf("Input length of edge of tetrahedron\n");
float a;
scanf("%f",&a);
printf("Volume of cylinder = %.2f",(a*a*a)/(6*1.41));
}