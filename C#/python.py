"""
Hacktoberfest 2021 Contribution Tracker
A Python tool to help track and manage your Hacktoberfest contributions
"""

import json
from datetime import datetime
from typing import List, Dict

class HacktoberfestTracker:
    def __init__(self, username: str):
        self.username = username
        self.contributions = []
        self.goal = 4
        self.filename = f"hacktoberfest_{username}.json"
        self.load_contributions()
    
    def add_contribution(self, repo_name: str, pr_number: int, 
                        title: str, status: str = "pending"):
        """Add a new contribution to the tracker"""
        contribution = {
            "repo": repo_name,
            "pr_number": pr_number,
            "title": title,
            "status": status,
            "date": datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        }
        self.contributions.append(contribution)
        self.save_contributions()
        print(f"✅ Added contribution: {title}")
    
    def update_status(self, pr_number: int, new_status: str):
        """Update the status of a contribution"""
        for contrib in self.contributions:
            if contrib["pr_number"] == pr_number:
                contrib["status"] = new_status
                self.save_contributions()
                print(f"✅ Updated PR #{pr_number} status to: {new_status}")
                return
        print(f"❌ PR #{pr_number} not found")
    
    def get_progress(self) -> Dict:
        """Get current progress statistics"""
        total = len(self.contributions)
        approved = sum(1 for c in self.contributions if c["status"] == "approved")
        pending = sum(1 for c in self.contributions if c["status"] == "pending")
        rejected = sum(1 for c in self.contributions if c["status"] == "rejected")
        
        return {
            "total": total,
            "approved": approved,
            "pending": pending,
            "rejected": rejected,
            "remaining": max(0, self.goal - approved),
            "goal_reached": approved >= self.goal
        }
    
    def display_progress(self):
        """Display progress in a formatted way"""
        stats = self.get_progress()
        
        print("\n" + "="*50)
        print(f"🎉 Hacktoberfest 2021 Progress for {self.username}")
        print("="*50)
        print(f"📊 Total Contributions: {stats['total']}")
        print(f"✅ Approved: {stats['approved']}/{self.goal}")
        print(f"⏳ Pending: {stats['pending']}")
        print(f"❌ Rejected: {stats['rejected']}")
        print(f"🎯 Remaining: {stats['remaining']}")
        
        progress_bar = self.create_progress_bar(stats['approved'], self.goal)
        print(f"\n{progress_bar}")
        
        if stats['goal_reached']:
            print("\n🎊 Congratulations! You've reached your goal! 🎊")
        else:
            print(f"\n💪 Keep going! {stats['remaining']} more to go!")
        print("="*50 + "\n")
    
    def create_progress_bar(self, current: int, total: int, length: int = 20) -> str:
        """Create a visual progress bar"""
        filled = int(length * current / total)
        bar = "█" * filled + "░" * (length - filled)
        percentage = (current / total) * 100
        return f"Progress: [{bar}] {percentage:.1f}%"
    
    def list_contributions(self):
        """List all contributions with details"""
        if not self.contributions:
            print("No contributions yet. Start contributing! 🚀")
            return
        
        print("\n📋 Your Contributions:")
        print("-" * 80)
        for i, contrib in enumerate(self.contributions, 1):
            status_emoji = {
                "approved": "✅",
                "pending": "⏳",
                "rejected": "❌"
            }
            emoji = status_emoji.get(contrib["status"], "❓")
            
            print(f"{i}. {emoji} {contrib['title']}")
            print(f"   Repository: {contrib['repo']}")
            print(f"   PR Number: #{contrib['pr_number']}")
            print(f"   Status: {contrib['status'].upper()}")
            print(f"   Date: {contrib['date']}")
            print("-" * 80)
    
    def save_contributions(self):
        """Save contributions to a JSON file"""
        data = {
            "username": self.username,
            "goal": self.goal,
            "contributions": self.contributions
        }
        with open(self.filename, 'w') as f:
            json.dump(data, f, indent=4)
    
    def load_contributions(self):
        """Load contributions from a JSON file"""
        try:
            with open(self.filename, 'r') as f:
                data = json.load(f)
                self.contributions = data.get("contributions", [])
        except FileNotFoundError:
            self.contributions = []
    
    def get_stats_by_repo(self) -> Dict:
        """Get contribution statistics by repository"""
        repo_stats = {}
        for contrib in self.contributions:
            repo = contrib["repo"]
            if repo not in repo_stats:
                repo_stats[repo] = {"total": 0, "approved": 0}
            repo_stats[repo]["total"] += 1
            if contrib["status"] == "approved":
                repo_stats[repo]["approved"] += 1
        return repo_stats


class ContributionHelper:
    """Helper class with useful methods for contributors"""
    
    @staticmethod
    def generate_pr_template() -> str:
        """Generate a PR description template"""
        template = """
## Description
<!-- Briefly describe your changes -->

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Code refactoring
- [ ] Performance improvement

## Testing
<!-- Describe how you tested your changes -->

## Checklist
- [ ] My code follows the project's style guidelines
- [ ] I have commented my code where necessary
- [ ] I have updated the documentation accordingly
- [ ] My changes generate no new warnings
- [ ] I have tested my changes

## Related Issues
<!-- Link any related issues here -->
Fixes #

## Screenshots (if applicable)
<!-- Add screenshots here -->

---
*This PR is part of Hacktoberfest 2021 🎉*
"""
        return template
    
    @staticmethod
    def suggest_contribution_ideas() -> List[str]:
        """Suggest contribution ideas for beginners"""
        ideas = [
            "Fix typos in documentation",
            "Add code comments for better clarity",
            "Write unit tests for existing functions",
            "Improve error handling",
            "Add input validation",
            "Optimize existing algorithms",
            "Create example usage scripts",
            "Add type hints to Python code",
            "Improve README with better examples",
            "Add missing docstrings",
            "Create a tutorial or guide",
            "Fix reported bugs",
            "Implement requested features",
            "Improve code formatting and style",
            "Add logging capabilities"
        ]
        return ideas
    
    @staticmethod
    def validate_pr_quality(pr_description: str) -> Dict:
        """Basic validation of PR quality"""
        checks = {
            "has_description": len(pr_description) > 50,
            "has_testing_info": "test" in pr_description.lower(),
            "has_checklist": "[" in pr_description and "]" in pr_description,
            "not_spam": len(pr_description.split()) > 10
        }
        
        score = sum(checks.values())
        return {
            "checks": checks,
            "score": score,
            "max_score": len(checks),
            "quality": "Good" if score >= 3 else "Needs Improvement"
        }


def main():
    """Main function to demonstrate the tracker"""
    print("🎃 Welcome to Hacktoberfest 2021 Tracker! 🎃\n")
    
    # Create a tracker instance
    tracker = HacktoberfestTracker("example_user")
    
    # Add some example contributions
    tracker.add_contribution(
        "awesome-python/project",
        1234,
        "Add feature: User authentication",
        "approved"
    )
    
    tracker.add_contribution(
        "open-source/repo",
        5678,
        "Fix bug: Memory leak in data processor",
        "approved"
    )
    
    tracker.add_contribution(
        "community/website",
        9012,
        "Update documentation for API endpoints",
        "pending"
    )
    
    # Display progress
    tracker.display_progress()
    
    # List all contributions
    tracker.list_contributions()
    
    # Show contribution ideas
    helper = ContributionHelper()
    print("\n💡 Contribution Ideas for Beginners:")
    for i, idea in enumerate(helper.suggest_contribution_ideas()[:5], 1):
        print(f"{i}. {idea}")
    
    # Generate PR template
    print("\n📝 PR Template Generated:")
    print(helper.generate_pr_template()[:200] + "...")


if __name__ == "__main__":
    main()
