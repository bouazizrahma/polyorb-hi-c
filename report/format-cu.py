#!/usr/bin/python

import sys
import re

# pretty print for CU
def pretty_print_cu(file):
    pretty_print_latex_cu(file)

def pretty_print_latex_cu(file):
    latex_file.write("\\subsection{Proof obligations for \\texttt{" + file.replace('_', '\_') + ".c}}\n\\label{proof:" + file + "}\n\n")
    latex_file.write("\\begin{longtable}[h]{l l r r r r r}\n")
    latex_file.write("\\toprule[1.5pt]\n")
    latex_file.write("\multicolumn{1}{l}{\\bfseries Function} & \multicolumn{1}{l}{\\bfseries VC} & \multicolumn{1}{l}{\\bfseries To be proved} & \multicolumn{1}{l}{\\bfseries Proved} & \multicolumn{1}{l}{\\bfseries Time (ms)}\\\\\\midrule\\endhead\n")
    for function in functions:
        pretty_print_info_latex(functions_prop[function], "\\texttt{" + function.replace('_', '\_') + "}", False)
    pretty_print_info_latex(total_cu, "\\textbf{Global for CU}", True)
    latex_file.write("\\bottomrule[1.5pt]\n")
    latex_file.write("\end{longtable}\n")

def pretty_print_info_latex(dic, label, last):
    latex_file.write(" " + label + " & Qed" + pretty_print_row_latex_cat(dic, 'qed', 0, 2, 'Tool'))
    latex_file.write(" & Alt-Ergo" + pretty_print_row_latex(dic, 'ergo'))
    latex_file.write("\\\\*[-1ex]")
    latex_file.write(" & Pre" + pretty_print_row_latex_cat(dic, 'call', 0, 6, 'Category'))
    latex_file.write(" & Post" + pretty_print_row_latex(dic, 'post'))
    latex_file.write(" & RTE" + pretty_print_row_latex(dic, 'assert_rte'))
    latex_file.write(" & Assigns" + pretty_print_row_latex(dic, 'assign'))
    latex_file.write(" & Loop" + pretty_print_row_latex(dic, 'loop'))
    latex_file.write(" & Other" + pretty_print_row_latex(dic, 'other'))
    latex_file.write("\\\\*[-1ex]")
    latex_file.write(" & \\cellcolor{gray!30} Total" + pretty_print_row_color_latex(dic, 'total'))
    latex_file.write("\\\\*[-2ex]")
    if (not last):
        latex_file.write("\\midrule")
    latex_file.write("\\pagebreak[2]")

def pretty_print_row_latex(dic, index):
    if dic[index][0] != 0:
        return " & " + str(dic[index][0]) + " & " + str(dic[index][1]) + " & " + str(dic[index][2]) + " \\\\*\n"
    else:
         return " & 0 & - & - \\\\*\n"

def pretty_print_row_latex_cat(dic, index, col, num, cat):
    if dic[index][0] != 0:
        return " & " + str(dic[index][0]) + " & " + str(dic[index][1]) + " & " + str(dic[index][2]) + col*"& " + "& \\rdelim]{" + str(num) + "}{1em}" + "& \\multirow{" + str(num) + "}{*}{\\rotatebox{90}{\\mbox{" + cat + "}}}" + " \\\\*\n"
    else:
         return " & 0 & - & - " + "& \\rdelim]{" + str(num) + "}{1em}" + "& \\multirow{" + str(num) + "}{*}{\\rotatebox{90}{\\mbox{" + cat + "}}}" + "\\\\*\n"

def pretty_print_row_color_latex(dic, index):
    if dic[index][0] != 0:
        return " & \\cellcolor{gray!30}" + str(dic[index][0]) + " & \\cellcolor{gray!30}" + str(dic[index][1]) + " & \\cellcolor{gray!30}" + str(dic[index][2]) + " \\\\\n"
    else:
         return " & \\cellcolor{gray!30} 0 & \\cellcolor{gray!30} - & \\cellcolor{gray!30} - \\\\\n"

def pretty_print_row_latex_global(dic, index):
    if dic[index][0] != 0:
        return " & " + str(dic[index][0]) + " & " + str(dic[index][1]) + " & " + str(dic[index][2]) + "&" + str(total_qed[index]) + "&" + str(total_ergo[index]) + " \\\\*\n"
    else:
         return " & 0 & - & - & - & -\\\\*\n"

def pretty_print_row_latex_cat_global(dic, index, num, cat):
    if dic[index][0] != 0:
        return " & " + str(dic[index][0]) + " & " + str(dic[index][1]) + " & " + str(dic[index][2]) + "&" + str(total_qed[index]) + "&" + str(total_ergo[index]) + "& \\rdelim]{" + str(num) + "}{1em}" + "& \\multirow{" + str(num) + "}{*}{\\rotatebox{90}{\\mbox{" + cat + "}}}" + " \\\\*\n"
    else:
         return " & 0 & - & - & - & -" + "& \\rdelim]{" + str(num) + "}{1em}" + "& \\multirow{" + str(num) + "}{*}{\\rotatebox{90}{\\mbox{" + cat + "}}}" + "\\\\*\n"

# close for pretty print for CU
def close_pretty_print_cu():
    close_pretty_print_latex_cu()

def close_pretty_print_latex_cu():
    latex_file.close()

# pretty print for global stats
def pretty_print_global():
    pretty_print_latex_global()

def pretty_print_latex_global():
    latex_file.write("\\subsection{Global results}\n\\label{proof:global}\n\n")
    latex_file.write("\\begin{longtable}{l r r r r r r r r r}\n")
    latex_file.write("\\toprule[1.5pt]\n")
    latex_file.write("\multicolumn{1}{l}{\\bfseries VC} & \multicolumn{1}{l}{\\bfseries To be proved} & \multicolumn{1}{l}{\\bfseries Proved} & \multicolumn{1}{l}{\\bfseries Time (ms)} & \multicolumn{1}{l}{\\bfseries Qed} & \multicolumn{1}{l}{\\bfseries Alt-Ergo}\\\\\\midrule\\endhead\n")
    latex_file.write("Qed" + pretty_print_row_latex_cat(total, 'qed', 2, 2, 'Tool'))
    latex_file.write("Alt-Ergo" + pretty_print_row_latex(total, 'ergo'))
    latex_file.write("\\\\*[-1ex]")
    latex_file.write("Pre" + pretty_print_row_latex_cat_global(total, 'call', 6, "Category"))
    latex_file.write("Post" + pretty_print_row_latex_global(total, 'post'))
    latex_file.write("RTE" + pretty_print_row_latex_global(total, 'assert_rte'))
    latex_file.write("Assigns" + pretty_print_row_latex_global(total, 'assign'))
    latex_file.write("Loop" + pretty_print_row_latex_global(total, 'loop'))
    latex_file.write("Other" + pretty_print_row_latex_global(total, 'other'))
    latex_file.write("\\\\[-1ex]")
    latex_file.write("\\cellcolor{gray!30} Total" + pretty_print_row_color_latex(total, 'total'))
    latex_file.write("\\\\*[-2ex]")
    latex_file.write("\\bottomrule[1.5pt]\n")
    latex_file.write("\\end{longtable}\n")

# close for pretty print for global
def close_pretty_print_global():
    close_pretty_print_latex_global()

def close_pretty_print_latex_global():
    latex_file.close()

# updating function
def update_dictionary(dic):
    dic['total'][0] += 1
    dic[prover][0] += 1
    dic[vc_type][0] += 1

    if valid:
        dic['total'][1] += 1
        dic['total'][2] += time
        dic[prover][1] += 1
        dic[prover][2] += time
        dic[vc_type][1] += 1
        dic[vc_type][2] += time


# main loop
total = dict(total=[0, 0, 0], ergo=[0, 0, 0], qed=[0, 0, 0], call=[0, 0, 0], post=[0, 0, 0], assign=[0, 0, 0], loop=[0, 0, 0], assert_rte=[0, 0, 0], other=[0, 0, 0])
total_qed = dict(call=0, post=0, assign=0, loop=0, assert_rte=0, other=0)
total_ergo = dict(call=0, post=0, assign=0, loop=0, assert_rte=0, other=0)

for c_file in sys.argv[1:]:
    file = c_file.replace('.c', '')
    latex_file = open("report_" + file + ".tex", 'w')

    # init
    functions = []
    functions_prop = {}
    cur_function = ""
    total_cu = dict(total=[0, 0, 0], ergo=[0, 0, 0], qed=[0, 0, 0], call=[0, 0, 0], post=[0, 0, 0], assign=[0, 0, 0], loop=[0, 0, 0], assert_rte=[0, 0, 0], other=[0, 0, 0])

    data = open("report_" + file + ".txt", "r")

    # main loop for compilation unit
    for line in data:
        # finding function names

        if line.startswith("[rte] annotating function"):
            fun_name = re.search('function (\w+)', line).group(1)
            functions_prop[fun_name] = dict(total=[0, 0, 0], ergo=[0, 0, 0], qed=[0, 0, 0], call=[0, 0, 0], post=[0, 0, 0], assign=[0, 0, 0], loop=[0, 0, 0], assert_rte=[0, 0, 0], other=[0,0,0])
            functions = sorted(functions_prop.keys())
            continue

        # analysing VC proofs
        my_match = re.match('\[wp\] \[(Alt-Ergo|Qed)\] Goal (.*) : (.*)', line)
        if my_match is not None:
            prover = 'ergo' if my_match.group(1) == 'Alt-Ergo' else 'qed'

            if 'Valid' in my_match.group(3):
                valid = True
                time_match = re.search('([0-9]*)(m?s)', my_match.group(3))
                if time_match is not None:
                    time = int(time_match.group(1)) if time_match.group(2) == 'ms' else int(time_match.group(1)) * 1000
                else:
                    time = 0
            else:
                valid = False
                time = 0

            # finding function name and VC type
            vc_name = my_match.group(2)
            my_fun_match = re.match('(.*)_(call|post|assert_rte|assign|loop|complete|disjoint).*', vc_name)
            my_fun_pos_name = my_fun_match.group(1)
            vc_type = my_fun_match.group(2)

            if vc_type == 'complete' or vc_type == 'disjoint':
                vc_type = 'other'

            if prover == 'ergo':
                total_ergo[vc_type] += 1
            else:
                total_qed[vc_type] += 1

            for name in functions:
                if re.search(name, my_fun_pos_name) is not None:
                    fun_name = name
                    break

            # updating dictionaries
            update_dictionary(functions_prop[fun_name])
            update_dictionary(total_cu)
            update_dictionary(total)

    # pretty print
    pretty_print_cu(file)
    close_pretty_print_cu()

    # close data
    data.close()

# pretty print global informations
latex_file = open('report_global.tex', 'w')
pretty_print_global()
close_pretty_print_global()