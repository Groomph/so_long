/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:31:27 by rsanchez          #+#    #+#             */
/*   Updated: 2022/01/04 22:21:59 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const static int	g_egg[2304] = {
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 14737376,
	15066341, 15658478, 15658478, 15790320, 15263719, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 14737376, 15066341, 15790320, 15790320,
	16185078, 16185078, 16316407, 16448250, 16448250, 15658478, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	14079189, 15000547, 15263719, 15790320, 15987185, 16579836, 16579836,
	16448250, 16579836, 16579836, 16579836, 16448250, 16185078, 15329512,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 15716481, 15716481, 15716481, 16447427, 14145495, 15066341,
	15263719, 15658478, 15987185, 16185078, 16448250, 16579836, 16579836,
	16579836, 16579836, 16579836, 16579836, 16448250, 16448250, 15987185,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	15716481, 15716481, 15716481, 14408667, 15000803, 15329512, 15790064,
	15987185, 16185078, 16448250, 16579836, 16579836, 16579836, 16579836,
	16579836, 16579836, 16579836, 16579836, 16579836, 16579836, 16053492,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 15716481,
	15716481, 13947859, 14671583, 15066341, 15724526, 15724526, 16185078,
	16448250, 16579836, 16579836, 16579836, 16579836, 8115569, 8115569,
	8050030, 8050030, 12446646, 16579836, 16579836, 16514043, 15790320,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 15716481, 13684687,
	14408667, 15000547, 15329512, 15790064, 15987185, 16448250, 16579836,
	16579836, 16579836, 7196257, 8050030, 7721834, 8050030, 8115569,
	8050030, 8050030, 8115569, 8115569, 16579836, 16448250, 15790320,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 15716481,
	15716481, 15716481, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 13158087, 13947859, 14737376,
	15066341, 15724526, 15987185, 16185078, 16448250, 16579836, 16579836,
	6999389, 7196257, 7328099, 7721834, 7721834, 7721834, 7721834,
	7721834, 8050030, 8050030, 8050030, 16514043, 16448250, 15658478,
	16447427, 16447427, 16447427, 16447427, 16447427, 15716481, 15716481,
	15716481, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 12895171, 13684687, 14408667, 14934755, 15263719,
	15724526, 16053236, 16316408, 16579836, 16579836, 6342226, 6539860,
	6999389, 6999389, 7196257, 7328099, 7459173, 7721834, 7721834,
	7721834, 7721834, 8050030, 7721834, 16579836, 16448250, 15658478,
	16447427, 16447427, 16447427, 16447427, 15716481, 15716481, 15716481,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	12368827, 13289671, 13947859, 14408667, 14934755, 15066341, 15790064,
	15987185, 16185078, 16579836, 6342226, 5815881, 6342226, 6539860,
	6736985, 6999389, 6999389, 7196257, 7328099, 7459173, 7459173,
	7459173, 7459173, 7459173, 7459173, 16579836, 16185078, 15329512,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 12895171,
	13421515, 13947859, 14671583, 14934755, 15263720, 15724526, 15987185,
	16316408, 16579836, 5815881, 5948747, 5948747, 6276944, 6539860,
	6736985, 6736985, 6736985, 7196257, 6999389, 7196257, 7459173,
	7328099, 7328099, 7328099, 7328099, 16579836, 15790320, 15066332,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 15716481, 15716481, 15716481, 12368827, 12895171, 13421515,
	13947859, 14671583, 14934755, 15263720, 15592684, 15987185, 16448250,
	5815881, 5815881, 5815881, 5948747, 6276944, 6146126, 6342226,
	6736985, 6539860, 6736985, 6999389, 6736985, 6999389, 6999389,
	6999389, 6999389, 6999389, 6736985, 16448250, 15856113, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	15716481, 15716481, 12105399, 12368827, 12895171, 13421515, 13947859,
	14474203, 14934755, 15066341, 15592684, 16053236, 16185078, 5422403,
	5422403, 5554756, 5751624, 5751624, 6146126, 6276944, 6342226,
	6342226, 6146126, 6539860, 6736985, 6539860, 6736985, 6539860,
	6736985, 6736985, 6539860, 16514043, 16053236, 14934755, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 15716481,
	15716481, 12105399, 12368827, 12895171, 13421515, 13816273, 14408667,
	14737376, 15066341, 15592684, 15790064, 15790320, 5422403, 5422403,
	5422403, 5422403, 5751624, 5751624, 5817927, 5817927, 6146126,
	6277713, 6277713, 6277713, 6146126, 6539860, 6539860, 6539860,
	6277713, 6276944, 6539860, 16448250, 15790320, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 11579312,
	12171193, 12368827, 12895171, 13289671, 13816273, 14408667, 14671583,
	15066341, 15263720, 15724527, 15790320, 5422403, 5027131, 5422403,
	5422403, 5554756, 5815881, 5751624, 5751624, 5817927, 6146126,
	5817927, 6146126, 6146126, 6146126, 6146126, 6146126, 6146126,
	6146126, 5817927, 16514043, 16185078, 15000803, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 11842483, 12105399,
	12368827, 12631999, 13289671, 13684687, 14211032, 14671583, 14934755,
	15263720, 15329512, 15527148, 5422403, 5027131, 5028923, 5028923,
	5028923, 5422403, 5422403, 5554756, 5751624, 5817927, 5817927,
	5817927, 5817927, 5817927, 5817927, 5817927, 5817927, 5817927,
	5751624, 16514043, 16250871, 15329512, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 11316140, 11842483, 11842483, 12171193,
	12697536, 12895171, 13750224, 14079189, 14408667, 14737376, 15066341,
	15658478, 15790064, 5027131, 5027131, 4830518, 5027131, 5028923,
	5028923, 5422403, 5554756, 5554756, 5422403, 5554756, 5554756,
	5554756, 5554756, 5948747, 5554756, 5554756, 5554756, 5357886,
	16579836, 16250871, 15790320, 14474204, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 11316140, 11842483, 12105399, 12105399, 12368827,
	12895171, 13223880, 13750224, 14211032, 14737376, 14737376, 15263720,
	15658478, 15790064, 4568371, 4830518, 4568371, 5027131, 5028923,
	5028923, 5028923, 5554756, 5028923, 5554756, 5554756, 5161021,
	5161021, 5554756, 5161021, 5554756, 5357886, 5161021, 16448250,
	16250871, 15790320, 15066332, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 11579312, 11842483, 11579312, 12105399, 12171193, 12697536,
	13223880, 13750224, 14079189, 14408667, 14737376, 15263720, 15066341,
	15790064, 5419836, 4568371, 4568371, 4568371, 4830518, 5028923,
	5028923, 5028923, 5161021, 5161021, 5161021, 5161021, 5161021,
	5161021, 5161021, 5161021, 5161021, 5161021, 16250871, 16250871,
	15856113, 15329512, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 11316140,
	11316140, 11842483, 11579312, 11842483, 12105399, 12697536, 13223880,
	13421515, 14079189, 14145495, 14671583, 15066341, 15263720, 15658478,
	15461098, 4371245, 4371245, 4568371, 4568371, 4830518, 4635187,
	4830518, 4635187, 5028923, 4832053, 5161021, 5028923, 5161021,
	4832053, 5161021, 5161021, 16514043, 16448250, 16250871, 16053492,
	15856113, 14408667, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 11316140, 11316140,
	11579312, 11579312, 11579312, 11842483, 12368827, 12697536, 12697536,
	13947859, 14145495, 14408667, 14737376, 15066341, 15329512, 15658478,
	15790320, 14740446, 4371245, 4568371, 4108842, 4568371, 4635187,
	4635187, 4635187, 4635187, 4635187, 4635187, 4635187, 4635187,
	4635187, 16579836, 16579836, 16185078, 16053236, 16053492, 15724526,
	14671583, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 15716481, 15716481, 15716481, 11316140, 11579312, 11579312,
	11579312, 2918935, 3642153, 4365364, 4168240, 12895171, 13421515,
	14079189, 14211032, 14671583, 15000547, 15066341, 15329512, 15658478,
	15790320, 15790320, 4108842, 4108842, 4108842, 4108842, 4568371,
	4371245, 4635187, 4108842, 4635187, 4635187, 4371245, 16579836,
	16579836, 16448250, 16448250, 16185078, 16053492, 15329512, 15000803,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	15716481, 15716481, 15716481, 11316140, 11316140, 11579312, 2786585,
	2919450, 3378722, 4167473, 4168240, 5422403, 13223880, 13816273,
	14079189, 14408667, 14737376, 14934755, 15329512, 15329512, 15658478,
	15790320, 15790320, 16053236, 15003106, 4108842, 4108842, 4108842,
	4108842, 4108842, 4108842, 16579836, 16448250, 16448250, 16579836,
	16448250, 16185078, 16185078, 15856113, 15329512, 15000803, 16052677,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 15716481,
	15716481, 11316140, 11316140, 11579312, 2850069, 2588949, 2918935,
	3244320, 3642153, 4168240, 4168240, 4168240, 13421515, 13816273,
	14408667, 14671583, 14737376, 14934755, 15263720, 15461098, 15658478,
	15658478, 15658478, 15856113, 15790320, 16185078, 16185078, 16250871,
	16448250, 16185078, 16316408, 16185078, 16185078, 16448250, 16316408,
	16185078, 16185078, 15856113, 15329512, 14934755, 13947859, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	11316140, 11316140, 11316140, 2456339, 2588949, 2786585, 3247647,
	3378722, 3642153, 4167473, 4168240, 13223880, 13684687, 14013908,
	14342617, 14408667, 14737376, 15000547, 15263720, 15263720, 15527148,
	15527148, 15790320, 15790320, 15790320, 15790320, 16119285, 16119285,
	16185078, 16185078, 16185078, 16185078, 16185078, 16053492, 16185078,
	15527148, 15658478, 15329512, 14934755, 14079189, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 11579312,
	11316140, 2455310, 2456339, 2588949, 2588949, 2786585, 3247647,
	3378722, 3642153, 3773482, 4168240, 13223880, 13684687, 14013908,
	14408667, 14474460, 14737376, 15000547, 15000547, 15329512, 15329512,
	15263720, 15658478, 15724527, 15724527, 15790320, 15790320, 16185078,
	15790320, 15790320, 15987185, 15790320, 15856113, 15724527, 15527148,
	15329512, 15198183, 14671583, 13947859, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 11579312, 11316140,
	2323986, 2456339, 2588949, 2588949, 2720790, 2919450, 3247647,
	3378722, 3642153, 3642153, 13223880, 13223880, 13750224, 14079189,
	14408667, 14474460, 14737376, 14737376, 15000803, 15066341, 15329512,
	15263720, 15263720, 15527148, 15724527, 15724527, 15790320, 15790320,
	15790320, 15790320, 15856113, 15724526, 15724526, 15592684, 15066341,
	15066341, 14474204, 13816273, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 11579312, 11316140, 2323986,
	2323986, 2456339, 2456339, 2588949, 2720790, 2786585, 3247647,
	3378722, 3445284, 12895171, 13223880, 13421515, 13684687, 13816273,
	14408667, 14408667, 14474460, 14737376, 14737376, 15066332, 15000547,
	15263720, 15263720, 15263720, 15263720, 15329512, 15461098, 15790320,
	15790320, 15527148, 15724526, 15658478, 15263719, 15000803, 14934755,
	14408667, 13750224, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 11579312, 11316140, 2323986, 2323986,
	2456339, 2456339, 2588949, 2588949, 2786585, 2786585, 3247647,
	3247647, 12368827, 12631999, 13158087, 13223880, 13684687, 13947859,
	14145495, 14145495, 14408667, 14408667, 14671583, 14737376, 14737376,
	14934755, 15000547, 15263720, 15263720, 15329512, 15329512, 15329512,
	15527148, 15329512, 15329512, 15000547, 14737376, 14737376, 14408667,
	13289671, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 11579312, 11316140, 2323986, 2323986, 2323986,
	2456339, 2456339, 2588949, 2720790, 2720790, 2919450, 2919450,
	12105399, 12368827, 12631999, 13158087, 13421515, 13421515, 13684687,
	13947859, 14145495, 14145495, 14342617, 14408667, 14671583, 14671583,
	14737376, 14737376, 14934755, 15000803, 15066341, 15066341, 3974170,
	3449119, 3449119, 3449119, 3449119, 8698234, 13947859, 13158087,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 11842483, 11316140, 2323986, 2323986, 2323986, 2323986,
	2456339, 2456339, 2588949, 2720790, 2720790, 2786585, 11579312,
	12105399, 12368827, 12631999, 12895171, 13223880, 13421515, 13816273,
	13816273, 14013908, 14013908, 14342617, 14342617, 14342617, 14474460,
	14474460, 15066332, 14737376, 13228229, 3449119, 3449119, 3119386,
	3251228, 3251228, 3119386, 3251228, 13223880, 13158087, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	11842483, 11842483, 9937812, 2521112, 2323986, 2323986, 2323986,
	2456339, 2456339, 2588949, 2720790, 2720790, 11316140, 11842483,
	11842483, 12368827, 12631999, 12895171, 13223880, 13223880, 13421515,
	13421515, 13816273, 14013908, 14013908, 14145495, 14145495, 14408667,
	14671583, 3251228, 3119386, 3449119, 3119386, 3119386, 3119386,
	3119386, 3119386, 3052314, 3052314, 12368827, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 14013370,
	11579312, 11579312, 2456339, 2323986, 2323986, 2323986, 2323986,
	2456339, 2456339, 2456339, 2720790, 11052968, 11316140, 11842483,
	12171193, 12171193, 12368827, 12895171, 12895171, 13158087, 13158087,
	13421515, 13816273, 13750224, 13816273, 13947859, 13947859, 3251228,
	3119386, 3119386, 3183899, 3119386, 3119386, 3119386, 3119386,
	3052314, 3051543, 2919450, 15657921, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 11842483,
	11579312, 10725792, 2323986, 2456339, 2323986, 2323986, 2323986,
	2323986, 2456339, 10460574, 10855589, 11052968, 11579312, 11842483,
	12105399, 12368827, 12171193, 12895171, 12895171, 12895171, 13158087,
	13289671, 13421515, 13421515, 13421515, 3119386, 3052314, 3183899,
	3052314, 3119386, 3052314, 3052314, 3051543, 2919450, 3051543,
	2919450, 2918935, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 11842483, 11842483,
	11579312, 2456339, 2456339, 2323986, 2323986, 2323986, 2323986,
	10460574, 10460574, 10855589, 10855589, 11316140, 11316140, 11842483,
	11842483, 12105399, 12171193, 12368827, 12895171, 12895171, 12895171,
	13158087, 13158087, 3051543, 3052314, 2919450, 3119386, 2919450,
	2919450, 2919450, 3052314, 2919450, 3051543, 2918935, 2918935,
	2588949, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 12105399, 11842483, 11579312,
	11579312, 11316140, 2456339, 2323986, 2455310, 10855589, 10592160,
	10592160, 10526367, 10855589, 10855589, 11316140, 11316140, 11842483,
	11842483, 12105399, 12171193, 12171193, 12368827, 12368827, 12697536,
	2919450, 2919450, 3051543, 2919450, 2919450, 2919450, 2919450,
	2919450, 2918935, 2918935, 2720790, 2720790, 2588949, 11316140,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 12105399, 11842483, 11579312,
	11316140, 11316140, 11316140, 10855589, 10855589, 10855589, 10460574,
	10526367, 10592160, 10855589, 11052968, 11316140, 11316140, 11449261,
	11842483, 12105399, 12105399, 12171193, 12368827, 12368827, 2786585,
	2720790, 2720790, 2919450, 2720790, 2720790, 2720790, 2720790,
	2720790, 2720790, 2720790, 2588949, 2588949, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 12171193, 12105399, 11842483, 11842483,
	11316140, 11316140, 11316140, 10855589, 10855589, 10855589, 10526367,
	10855589, 10855589, 10855589, 10855589, 11316140, 11316140, 11316140,
	11449261, 11842483, 11842483, 11842483, 2456339, 2588949, 2588949,
	2720790, 2588949, 2588949, 2720790, 2720790, 2720790, 2588949,
	2456339, 2588949, 2323986, 2456339, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 12171193, 12105399, 11842483, 11579312,
	11316140, 11316140, 11316140, 11052968, 11052968, 10855589, 10855589,
	10855589, 10855589, 10855589, 11052968, 11316140, 11316140, 11316140,
	11316140, 11579312, 11579312, 2850069, 2456339, 2456339, 2456339,
	2456339, 2456339, 2456339, 2456339, 2456339, 2456339, 2323986,
	2323986, 2323986, 16052677, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 12171193, 11842483, 11842483, 11842483,
	11316140, 11316140, 11316140, 11052968, 11052968, 10855589, 10855589,
	10855589, 10855589, 10855589, 10855589, 11316140, 11316140, 11316140,
	11316140, 2323986, 2323986, 2323986, 2323986, 2323986, 2456339,
	2323986, 2456339, 2323986, 2323986, 2323986, 2323986, 2456339,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 12368827, 12171193, 12105399, 11842483, 11579312,
	11579311, 11579311, 11316140, 11316140, 11316140, 10855589, 11052967,
	10855589, 10855589, 10855589, 11052968, 11052967, 11052968, 11052968,
	2323986, 2323986, 2323986, 2323986, 2323986, 2323986, 2323986,
	2323986, 2323986, 2323986, 2323986, 2588949, 12171193, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 15716481, 15716481, 15716481, 16447427,
	16447427, 16447427, 12368827, 12171193, 12171193, 11842483, 11842483,
	11579312, 11579311, 11316140, 11316140, 11316140, 11052968, 11052967,
	11052968, 10855589, 11052968, 11052967, 11052967, 11316140, 2323986,
	2521112, 2456339, 2323986, 2456339, 2323986, 2456339, 2456339,
	2456339, 2456339, 2588949, 11842483, 15716481, 15716481, 15716481,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 15716481, 15716481, 15716481, 16447427, 16447427,
	16447427, 16447427, 12631999, 12368827, 12171193, 11842483, 11842483,
	11579312, 11316140, 11316140, 11316140, 11316140, 11316140, 11052967,
	11052967, 11052967, 11052968, 11052968, 11052967, 2456339, 2323986,
	2323986, 2456339, 2323986, 2456339, 2456339, 2323986, 2456339,
	2456339, 12105399, 16447427, 15716481, 15716481, 15716481, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 15716481, 15716481, 15716481, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 12368827, 12105399, 12105399, 11842483,
	11842483, 11579312, 11316140, 11316140, 11316140, 11316140, 11316140,
	11316140, 11052968, 11052968, 11316140, 2456339, 2456339, 2323986,
	2456339, 2456339, 2456339, 2456339, 2588949, 2588949, 15066048,
	16052677, 16447427, 15716481, 15716481, 15716481, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 12368827, 12368827, 12368827, 12105399,
	11842483, 11842483, 11842483, 11449261, 11316140, 11316140, 11316140,
	11449261, 11316140, 11316140, 2456339, 2850069, 2456339, 2456339,
	2456339, 2456339, 2588949, 11449261, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 15716481, 15716481, 12697536, 12171193, 12105399,
	11842483, 12105399, 11842483, 11842483, 11842483, 11842483, 11449261,
	11316140, 11316140, 11316140, 2786585, 2456339, 2456339, 2720790,
	12105399, 16052677, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 12895171, 12368827,
	12171193, 12105399, 12105399, 12105399, 11842483, 11842483, 11842483,
	11842483, 11842483, 11842483, 12105399, 12105399, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	12368827, 12368827, 12368827, 12368827, 12368827, 12368827, 12171193,
	12171193, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427,
	16447427, 16447427, 16447427, 16447427, 16447427, 16447427, 16447427
};

void	draw_egg(t_img *img, int cursor)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < 2304)
	{
		img->addr[cursor] = g_egg[i];
		cursor++;
		i++;
		x++;
		if (x == 48)
		{
			cursor -= x;
			cursor = next_line(img, cursor);
			x = 0;
		}
	}
}
/*
   void	draw_ground(t_img *img, int cursor)
   {
   int	x;
   int	y;
   int	i;

   y = 0;
   i = 0;
   while (y < 48)
   {
   x = 0;
   while (x < 48)
   {
   img->addr[cursor] = sand[i];
   x++;
   i++
   cursor++;
   }
   cursor -= x;
   cursor = next_line(img, cursor);
   y++;
   }
   }
   */
