#ifndef MAFIA_GEN_CONTEXT_
#define MAFIA_GEN_CONTEXT_

/** @file gen-context.h overall information for generating points */

// forward references
struct Cluster;

/** general information for generation of points */
struct GenContext {
	
	/** the total number of points to generate */
	int n;
	/** dimensionality of the dataset */
	int d;
	/** minimum dimensionality of the cluster */
	int kmin;
	/** maximum dimensionality of the cluster, auto-clamped at d */
	int kmax;
	/** the number of clusters to generate */
	int m;
	/** the type of the underlying clusters (box or sphere) */
	int ct;
	/** the total fraction of the points belonging to the cluster(s) */
	double cf;
	/** the minimum extent of the point region */
	double pmin;
	/** the maximum extent of the point region */
	double pmax;
	/** the cluster size, in each dimension */
	double csize;

	/** the pointers to the underlying clusters  */
	Cluster **clusters;

	/** the default constructor */
	GenContext();

	/** generates the template for generating the clusters */
	void generate_template(void);

	/** generates a single point, with the specified number of dimensions */
	void generate_point(double *p) const;

	/** generates other (non-cluster) point dimensions uniformly in the extent 
			@param p[out] the point to generate
			@param cluster_dims the dimensions which belong to the cluster and were
			generated by the cluster; may be 0, in which case all dimensions must
			be generated
			@param k the size of cluster dimensions, ignored if cluster_dims is 0
	 */
	void generate_other_point_dims(double *p, const int *cluster_dims, int k) const;

	/** allocates (with new[]) and generates points */
	double *generate_points() const;

	/** prints out the context information (including the clusters) */
	void print_info() const;

	/** the destructor */
	~GenContext();

}; // class GenContext

/** generate a random double value within the specific range */
double drandom(double a, double b);

/** generate an integer random value within the [a, b] range */
int irandom(int a, int b);
 
#endif