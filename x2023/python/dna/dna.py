import csv
import sys


def main():
    #  Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    #  Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as datafile:
        read1 = csv.DictReader(datafile)
        for row in read1:
            database.append(row)

    #  Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as seqfile:
        dna_seq = seqfile.read()

    #  Find longest match of each STR in DNA sequence
    subsequences = list((database[0].keys()))[1:]

    longestresult = {}
    for subsequence in subsequences:
        longestresult[subsequence] = longest_match(dna_seq, subsequence)

    #  Check database for matching profiles
    for person in database:
        match = 0
        for subsequence in subsequences:
            if int(person[subsequence]) == longestresult[subsequence]:
                match += 1

        ## if all match then name of person
        if match == len(subsequences):
            print(person["name"])
            return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
