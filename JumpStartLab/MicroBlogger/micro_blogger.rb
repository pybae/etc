require 'jumpstart_auth'

class MicroBlogger
  attr_reader :client

  def initialize
    puts "Initalizing MicroBlogger!"
    @client = JumpstartAuth.twitter
  end

  def tweet(message)
    if message.length > 140
      puts "Message is longer than 140 characters"
    else
      @client.update(message)
      puts "Tweet successful!"
    end
  end

  def dm(target, message)
    puts "Trying to send #{target} this message: "
    puts message
    screen_names = @client.followers.collect { |follower| @client.user(follower).screen_name }

    if screen_names.include? target
      tweet("@#{target} #{message}")
    else
      puts "Target is not following you"
    end

  end

  def run
    command = ""
    while command != 'q'
      printf "Enter command: "
      input = gets.chomp
      parts = input.split(" ")
      command = parts[0]
      
      case command
        when 't'
          tweet(parts[1..-1].join(" "))
        when 'dm'
          dm(parts[1], parts[2..-1].join(" "))
        when 'q'
          puts "Goodbye!"
        else
          puts "Sorry, I don't know how to parse that command: #{command}"
      end
    end
  end
end

blogger = MicroBlogger.new
blogger.run
