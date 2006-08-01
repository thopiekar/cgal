// Copyright (c) 2000-2004  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Herve Bronnimann, Sylvain Pion, Susan Hert

// This file is intentionally not protected against re-inclusion.
// It's aimed at being included from within a kernel traits class, this
// way we share more code.

// It is the responsability of the including file to correctly set the 2
// macros CGAL_Kernel_pred and CGAL_Kernel_cons.
// And they are #undefed at the end of this file.

CGAL_Kernel_pred(Angle_2,
		 angle_2_object)
CGAL_Kernel_pred(Angle_3,
		 angle_3_object)
CGAL_Kernel_pred(Are_ordered_along_line_2,
		 are_ordered_along_line_2_object)
CGAL_Kernel_pred(Are_ordered_along_line_3,
		 are_ordered_along_line_3_object)
CGAL_Kernel_pred(Are_parallel_2,
		 are_parallel_2_object)
CGAL_Kernel_pred(Are_parallel_3,
		 are_parallel_3_object)
CGAL_Kernel_pred(Are_strictly_ordered_along_line_2,
		 are_strictly_ordered_along_line_2_object)
CGAL_Kernel_pred(Are_strictly_ordered_along_line_3,
		 are_strictly_ordered_along_line_3_object)
CGAL_Kernel_cons(Assign_2,
		 assign_2_object)
CGAL_Kernel_cons(Assign_3,
		 assign_3_object)
CGAL_Kernel_pred(Bounded_side_2,
		 bounded_side_2_object)
CGAL_Kernel_pred(Bounded_side_3,
		 bounded_side_3_object)
CGAL_Kernel_pred(Collinear_are_ordered_along_line_2,
		 collinear_are_ordered_along_line_2_object)
CGAL_Kernel_pred(Collinear_are_ordered_along_line_3,
		 collinear_are_ordered_along_line_3_object)
CGAL_Kernel_pred(Collinear_are_strictly_ordered_along_line_2,
		 collinear_are_strictly_ordered_along_line_2_object)
CGAL_Kernel_pred(Collinear_are_strictly_ordered_along_line_3,
		 collinear_are_strictly_ordered_along_line_3_object)
CGAL_Kernel_pred(Collinear_has_on_2,
		 collinear_has_on_2_object)
CGAL_Kernel_pred(Collinear_2,
		 collinear_2_object)
CGAL_Kernel_pred(Collinear_3,
		 collinear_3_object)
CGAL_Kernel_pred(Compare_angle_with_x_axis_2,
		 compare_angle_with_x_axis_2_object)
CGAL_Kernel_pred(Compare_distance_2,
		 compare_distance_2_object)
CGAL_Kernel_pred(Compare_distance_3,
		 compare_distance_3_object)
CGAL_Kernel_pred(Compare_slope_2,
		 compare_slope_2_object)
CGAL_Kernel_pred(Compare_x_at_y_2,
		 compare_x_at_y_2_object)
CGAL_Kernel_pred(Compare_xyz_3,
		 compare_xyz_3_object)
CGAL_Kernel_pred(Compare_xy_2,
		 compare_xy_2_object)
CGAL_Kernel_pred(Compare_xy_3,
		 compare_xy_3_object)
CGAL_Kernel_pred(Compare_x_2,
		 compare_x_2_object)
CGAL_Kernel_pred(Compare_x_3,
		 compare_x_3_object)
CGAL_Kernel_pred(Compare_y_at_x_2,
		 compare_y_at_x_2_object)
CGAL_Kernel_pred(Compare_y_2,
		 compare_y_2_object)
CGAL_Kernel_pred(Compare_y_3,
		 compare_y_3_object)
CGAL_Kernel_pred(Compare_yx_2,
		 compare_yx_2_object)
CGAL_Kernel_pred(Compare_z_3,
		 compare_z_3_object)
CGAL_Kernel_cons(Compute_a_2,
		 compute_a_2_object)
CGAL_Kernel_cons(Compute_b_2,
		 compute_b_2_object)
CGAL_Kernel_cons(Compute_c_2,
		 compute_c_2_object)
CGAL_Kernel_cons(Compute_area_2,
		 compute_area_2_object)
CGAL_Kernel_cons(Compute_area_3,
		 compute_area_3_object)
CGAL_Kernel_cons(Compute_scalar_product_2,
		 compute_scalar_product_2_object)
CGAL_Kernel_cons(Compute_scalar_product_3,
		 compute_scalar_product_3_object)
CGAL_Kernel_cons(Compute_squared_area_3,
		 compute_squared_area_3_object)
CGAL_Kernel_cons(Compute_squared_distance_2,
		 compute_squared_distance_2_object)
CGAL_Kernel_cons(Compute_squared_distance_3,
		 compute_squared_distance_3_object)
CGAL_Kernel_cons(Compute_squared_length_2,
		 compute_squared_length_2_object)
CGAL_Kernel_cons(Compute_squared_length_3,
		 compute_squared_length_3_object)
CGAL_Kernel_cons(Compute_squared_radius_2,
		 compute_squared_radius_2_object)
CGAL_Kernel_cons(Compute_squared_radius_3,
		 compute_squared_radius_3_object)
CGAL_Kernel_cons(Compute_volume_3,
		 compute_volume_3_object)
CGAL_Kernel_cons(Compute_x_2,
		 compute_x_2_object)
CGAL_Kernel_cons(Compute_y_2,
		 compute_y_2_object)
CGAL_Kernel_cons(Compute_dx_2,
		 compute_dx_2_object)
CGAL_Kernel_cons(Compute_dy_2,
		 compute_dy_2_object)
CGAL_Kernel_cons(Compute_hx_2,
		 compute_hx_2_object)
CGAL_Kernel_cons(Compute_hy_2,
		 compute_hy_2_object)
CGAL_Kernel_cons(Compute_hw_2,
		 compute_hw_2_object)
CGAL_Kernel_cons(Compute_x_at_y_2,
		 compute_x_at_y_2_object)
CGAL_Kernel_cons(Compute_y_at_x_2,
		 compute_y_at_x_2_object)
CGAL_Kernel_cons(Compute_xmin_2,
		 compute_xmin_2_object)
CGAL_Kernel_cons(Compute_xmax_2,
		 compute_xmax_2_object)
CGAL_Kernel_cons(Compute_ymin_2,
		 compute_ymin_2_object)
CGAL_Kernel_cons(Compute_ymax_2,
		 compute_ymax_2_object)
CGAL_Kernel_cons(Compute_xmin_3,
		 compute_xmin_3_object)
CGAL_Kernel_cons(Compute_xmax_3,
		 compute_xmax_3_object)
CGAL_Kernel_cons(Compute_ymin_3,
		 compute_ymin_3_object)
CGAL_Kernel_cons(Compute_ymax_3,
		 compute_ymax_3_object)
CGAL_Kernel_cons(Compute_zmin_3,
		 compute_zmin_3_object)
CGAL_Kernel_cons(Compute_zmax_3,
		 compute_zmax_3_object)
CGAL_Kernel_cons(Construct_base_vector_3,
		 construct_base_vector_3_object)
CGAL_Kernel_cons(Construct_bisector_2,
		 construct_bisector_2_object)
CGAL_Kernel_cons(Construct_bisector_3,
		 construct_bisector_3_object)
CGAL_Kernel_cons(Construct_center_2,
		 construct_center_2_object)
CGAL_Kernel_cons(Construct_center_3,
		 construct_center_3_object)
CGAL_Kernel_cons(Construct_centroid_2,
		 construct_centroid_2_object)
CGAL_Kernel_cons(Construct_centroid_3,
		 construct_centroid_3_object)
CGAL_Kernel_cons(Construct_circle_2,
		 construct_circle_2_object)
CGAL_Kernel_cons(Construct_circumcenter_2,
		 construct_circumcenter_2_object)
CGAL_Kernel_cons(Construct_circumcenter_3,
		 construct_circumcenter_3_object)
CGAL_Kernel_cons(Construct_cross_product_vector_3,
		 construct_cross_product_vector_3_object)
CGAL_Kernel_cons(Construct_direction_2,
		 construct_direction_2_object)
CGAL_Kernel_cons(Construct_direction_3,
		 construct_direction_3_object)
CGAL_Kernel_cons(Construct_iso_cuboid_3,
		 construct_iso_cuboid_3_object)
CGAL_Kernel_cons(Construct_iso_rectangle_2,
		 construct_iso_rectangle_2_object)
CGAL_Kernel_cons(Construct_lifted_point_3,
		 construct_lifted_point_3_object)
CGAL_Kernel_cons(Construct_line_2,
		 construct_line_2_object)
CGAL_Kernel_cons(Construct_line_3,
		 construct_line_3_object)
CGAL_Kernel_cons(Construct_midpoint_2,
		 construct_midpoint_2_object)
CGAL_Kernel_cons(Construct_midpoint_3,
		 construct_midpoint_3_object)
CGAL_Kernel_cons(Construct_min_vertex_2,
                 construct_min_vertex_2_object)
CGAL_Kernel_cons(Construct_max_vertex_2,
                 construct_max_vertex_2_object)
CGAL_Kernel_cons(Construct_min_vertex_3,
                 construct_min_vertex_3_object)
CGAL_Kernel_cons(Construct_max_vertex_3,
                 construct_max_vertex_3_object)
CGAL_Kernel_cons(Construct_object_2,
                 construct_object_2_object)
CGAL_Kernel_cons(Construct_object_3,
                 construct_object_3_object)
CGAL_Kernel_cons(Construct_opposite_circle_2,
		 construct_opposite_circle_2_object)
CGAL_Kernel_cons(Construct_opposite_direction_2,
		 construct_opposite_direction_2_object)
CGAL_Kernel_cons(Construct_opposite_direction_3,
		 construct_opposite_direction_3_object)
CGAL_Kernel_cons(Construct_opposite_line_2,
		 construct_opposite_line_2_object)
CGAL_Kernel_cons(Construct_opposite_line_3,
		 construct_opposite_line_3_object)
CGAL_Kernel_cons(Construct_opposite_plane_3,
		 construct_opposite_plane_3_object)
CGAL_Kernel_cons(Construct_opposite_ray_2,
		 construct_opposite_ray_2_object)
CGAL_Kernel_cons(Construct_opposite_ray_3,
		 construct_opposite_ray_3_object)
CGAL_Kernel_cons(Construct_opposite_segment_2,
		 construct_opposite_segment_2_object)
CGAL_Kernel_cons(Construct_opposite_segment_3,
		 construct_opposite_segment_3_object)
CGAL_Kernel_cons(Construct_opposite_sphere_3,
		 construct_opposite_sphere_3_object)
CGAL_Kernel_cons(Construct_opposite_triangle_2,
		 construct_opposite_triangle_2_object)
CGAL_Kernel_cons(Construct_opposite_vector_2,
		 construct_opposite_vector_2_object)
CGAL_Kernel_cons(Construct_difference_of_vectors_2,
		 construct_difference_of_vectors_2_object)
CGAL_Kernel_cons(Construct_sum_of_vectors_2,
		 construct_sum_of_vectors_2_object)
CGAL_Kernel_cons(Construct_opposite_vector_3,
		 construct_opposite_vector_3_object)
CGAL_Kernel_cons(Construct_orthogonal_vector_3,
		 construct_orthogonal_vector_3_object)
CGAL_Kernel_cons(Construct_perpendicular_direction_2,
		 construct_perpendicular_direction_2_object)
CGAL_Kernel_cons(Construct_perpendicular_line_2,
		 construct_perpendicular_line_2_object)
CGAL_Kernel_cons(Construct_perpendicular_line_3,
		 construct_perpendicular_line_3_object)
CGAL_Kernel_cons(Construct_perpendicular_plane_3,
		 construct_perpendicular_plane_3_object)
CGAL_Kernel_cons(Construct_perpendicular_vector_2,
		 construct_perpendicular_vector_2_object)
CGAL_Kernel_cons(Construct_plane_3,
		 construct_plane_3_object)
CGAL_Kernel_cons(Construct_point_on_2,
		 construct_point_on_2_object)
CGAL_Kernel_cons(Construct_point_on_3,
		 construct_point_on_3_object)
CGAL_Kernel_cons(Construct_point_2,
		 construct_point_2_object)
CGAL_Kernel_cons(Construct_point_3,
		 construct_point_3_object)
CGAL_Kernel_cons(Construct_projected_point_2,
		 construct_projected_point_2_object)
CGAL_Kernel_cons(Construct_projected_point_3,
		 construct_projected_point_3_object)
CGAL_Kernel_cons(Construct_projected_xy_point_2,
		 construct_projected_xy_point_2_object)
CGAL_Kernel_cons(Construct_ray_2,
		 construct_ray_2_object)
CGAL_Kernel_cons(Construct_ray_3,
		 construct_ray_3_object)
CGAL_Kernel_cons(Construct_scaled_vector_2,
		 construct_scaled_vector_2_object)
CGAL_Kernel_cons(Construct_divided_vector_2,
		 construct_divided_vector_2_object)
CGAL_Kernel_cons(Construct_scaled_vector_3,
		 construct_scaled_vector_3_object)
CGAL_Kernel_cons(Construct_second_point_2,
		 construct_second_point_2_object)
CGAL_Kernel_cons(Construct_segment_2,
		 construct_segment_2_object)
CGAL_Kernel_cons(Construct_source_2,
		 construct_source_2_object)
CGAL_Kernel_cons(Construct_segment_3,
		 construct_segment_3_object)
CGAL_Kernel_cons(Construct_sphere_3,
		 construct_sphere_3_object)
#ifndef CGAL_NO_DEPRECATED_CODE
CGAL_Kernel_cons(Construct_supporting_line_2,
		 construct_supporting_line_2_object)
CGAL_Kernel_cons(Construct_supporting_line_3,
		 construct_supporting_line_3_object)
#endif // CGAL_NO_DEPRECATED_CODE
CGAL_Kernel_cons(Construct_supporting_plane_3,
		 construct_supporting_plane_3_object)
CGAL_Kernel_cons(Construct_target_2,
		 construct_target_2_object)
CGAL_Kernel_cons(Construct_tetrahedron_3,
		 construct_tetrahedron_3_object)
CGAL_Kernel_cons(Construct_translated_point_2,
		 construct_translated_point_2_object)
CGAL_Kernel_cons(Construct_translated_point_3,
		 construct_translated_point_3_object)
CGAL_Kernel_cons(Construct_triangle_2,
		 construct_triangle_2_object)
CGAL_Kernel_cons(Construct_triangle_3,
		 construct_triangle_3_object)
CGAL_Kernel_cons(Construct_vector_2,
		 construct_vector_2_object)
CGAL_Kernel_cons(Construct_vector_3,
		 construct_vector_3_object)
CGAL_Kernel_cons(Construct_vertex_2,
		 construct_vertex_2_object)
CGAL_Kernel_cons(Construct_vertex_3,
		 construct_vertex_3_object)
CGAL_Kernel_cons(Construct_bbox_2,
		 construct_bbox_2_object)
CGAL_Kernel_cons(Construct_bbox_3,
		 construct_bbox_3_object)
CGAL_Kernel_cons(Construct_cartesian_const_iterator_2,
		 construct_cartesian_const_iterator_2_object)
CGAL_Kernel_cons(Construct_cartesian_const_iterator_3,
		 construct_cartesian_const_iterator_3_object)
CGAL_Kernel_pred(Coplanar_orientation_3,
		 coplanar_orientation_3_object)
CGAL_Kernel_pred(Coplanar_side_of_bounded_circle_3,
		 coplanar_side_of_bounded_circle_3_object)
CGAL_Kernel_pred(Coplanar_3,
		 coplanar_3_object)
CGAL_Kernel_pred(Counterclockwise_in_between_2,
		 counterclockwise_in_between_2_object)
CGAL_Kernel_pred(Do_intersect_2,
		 do_intersect_2_object)
CGAL_Kernel_cons(Do_intersect_3,
		 do_intersect_3_object)
CGAL_Kernel_pred(Equal_xy_3,
		 equal_xy_3_object)
CGAL_Kernel_pred(Equal_x_2,
		 equal_x_2_object)
CGAL_Kernel_pred(Equal_x_3,
		 equal_x_3_object)
CGAL_Kernel_pred(Equal_y_2,
		 equal_y_2_object)
CGAL_Kernel_pred(Equal_y_3,
		 equal_y_3_object)
CGAL_Kernel_pred(Equal_z_3,
		 equal_z_3_object)
CGAL_Kernel_pred(Equal_2,
		 equal_2_object)
CGAL_Kernel_pred(Equal_3,
		 equal_3_object)
CGAL_Kernel_pred(Has_on_boundary_2,
		 has_on_boundary_2_object)
CGAL_Kernel_pred(Has_on_boundary_3,
		 has_on_boundary_3_object)
CGAL_Kernel_pred(Has_on_bounded_side_2,
		 has_on_bounded_side_2_object)
CGAL_Kernel_pred(Has_on_bounded_side_3,
		 has_on_bounded_side_3_object)
CGAL_Kernel_pred(Has_on_negative_side_2,
		 has_on_negative_side_2_object)
CGAL_Kernel_pred(Has_on_negative_side_3,
		 has_on_negative_side_3_object)
CGAL_Kernel_pred(Has_on_positive_side_2,
		 has_on_positive_side_2_object)
CGAL_Kernel_pred(Has_on_positive_side_3,
		 has_on_positive_side_3_object)
CGAL_Kernel_pred(Has_on_unbounded_side_2,
		 has_on_unbounded_side_2_object)
CGAL_Kernel_pred(Has_on_unbounded_side_3,
		 has_on_unbounded_side_3_object)
CGAL_Kernel_pred(Has_on_2,
		 has_on_2_object)
CGAL_Kernel_pred(Has_on_3,
		 has_on_3_object)
CGAL_Kernel_cons(Intersect_2,
		 intersect_2_object)
CGAL_Kernel_cons(Intersect_3,
		 intersect_3_object)
CGAL_Kernel_pred(Is_degenerate_2,
		 is_degenerate_2_object)
CGAL_Kernel_pred(Is_degenerate_3,
		 is_degenerate_3_object)
CGAL_Kernel_pred(Is_horizontal_2,
		 is_horizontal_2_object)
CGAL_Kernel_pred(Is_vertical_2,
		 is_vertical_2_object)
CGAL_Kernel_pred(Left_turn_2,
                 left_turn_2_object)
CGAL_Kernel_pred(Less_distance_to_point_2,
                 less_distance_to_point_2_object)
CGAL_Kernel_pred(Less_distance_to_point_3,
                 less_distance_to_point_3_object)
CGAL_Kernel_pred(Less_rotate_ccw_2,
		 less_rotate_ccw_2_object)
CGAL_Kernel_pred(Less_signed_distance_to_line_2,
                 less_signed_distance_to_line_2_object)
CGAL_Kernel_pred(Less_signed_distance_to_plane_3,
		 less_signed_distance_to_plane_3_object)
CGAL_Kernel_pred(Less_xyz_3,
		 less_xyz_3_object)
CGAL_Kernel_pred(Less_xy_2,
		 less_xy_2_object)
CGAL_Kernel_pred(Less_xy_3,
		 less_xy_3_object)
CGAL_Kernel_pred(Less_x_2,
		 less_x_2_object)
CGAL_Kernel_pred(Less_x_3,
		 less_x_3_object)
CGAL_Kernel_pred(Less_yx_2,
		 less_yx_2_object)
CGAL_Kernel_pred(Less_y_2,
		 less_y_2_object)
CGAL_Kernel_pred(Less_y_3,
		 less_y_3_object)
CGAL_Kernel_pred(Less_z_3,
		 less_z_3_object)
CGAL_Kernel_pred(Orientation_2,
		 orientation_2_object)
CGAL_Kernel_pred(Orientation_3,
		 orientation_3_object)
CGAL_Kernel_pred(Oriented_side_2,
		 oriented_side_2_object)
CGAL_Kernel_pred(Oriented_side_3,
		 oriented_side_3_object)
CGAL_Kernel_pred(Side_of_bounded_circle_2,
		 side_of_bounded_circle_2_object)
CGAL_Kernel_pred(Side_of_bounded_sphere_3,
		 side_of_bounded_sphere_3_object)
CGAL_Kernel_pred(Side_of_oriented_circle_2,
		 side_of_oriented_circle_2_object)
CGAL_Kernel_pred(Side_of_oriented_sphere_3,
		 side_of_oriented_sphere_3_object)

#undef CGAL_Kernel_pred
#undef CGAL_Kernel_cons
