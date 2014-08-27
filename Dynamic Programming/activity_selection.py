# An implementation of the activity selction problem, in which we are given a list of activities
# with start time and end time, and then determine the max amount of activities that can be
# chosen in a certain time frame.

# The input will be of the following format:
#   Time frame: {start time} {end time}
#   Number of events:
#   Event 1: {start time} {end time}
#   Event 2: {start time} {end time}
#   ...
#   Event n: {start time} {end time}
def activity_selection (time_frame, events):
    # first we need to sort the events
    events.sort(key=lambda event: event[1])
    optimal_events = Array.new()
    current_event = events.shift
    while current_event != nil and current_event[1] < time_frame[1]
        # take the element with lowest starting time
        optimal_events << current_event if current_event[0] >= time_frame[0]
        # now remove all elements that have conflicting starting time
        events.shift while optimal_events.last[1] > events.first
        current_event = events.shift
    end
    print_array(optimal_events)
end

print "Time frame: "
time_frame = gets.split(" ")
abort "Time frame requires a start time and end time" if time_frame.length != 2

print "Number of events: "
num_events = gets.chomp.to_i

events = Array.new(num_events)
for i in 0...num_events
    print "Event #{i + 1}: "
    events[i] = gets.split(" ").each{ |x|
        x = x.to_i
        abort "Event time cannot be negative" if x < 0
    }
    abort "Event #{i + 1} requires a start time and end time" if events[i].length != 2
end

activity_selection(time_frame, events)
